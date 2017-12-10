#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdint.h>
#include <string.h>
#include <cstdio>
#include <cassert>
#include <omp.h>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;


#define private public


// load mnist data
uint32_t h2l(uint32_t data) {
    uint32_t a = (data & 0xFF) << 24;
    uint32_t b = (data >> 8) & 0xFF;
    b <<= 16;
    uint32_t c = (data >> 16) & 0xFF;
    c <<= 8;
    uint32_t d = (data >> 24) & 0xFF;
    return a + b + c + d;
}

void load_image_data(const char* filename, vector<vector<double> >& data) {
    FILE* fin = fopen(filename, "rb");
    fseek (fin , 0 , SEEK_END);
    int fsize = ftell(fin);
    rewind(fin);
    char* buffer = (char*) malloc (sizeof(char)*fsize);
    fread (buffer, 1, fsize, fin);
    
    uint32_t magic_num;
    uint32_t image_num;
    uint32_t row_num;
    uint32_t col_num;

    memcpy(&magic_num, buffer, 4);
    memcpy(&image_num, buffer+4, 4);
    memcpy(&row_num, buffer+8, 4);
    memcpy(&col_num, buffer+12, 4);
    magic_num = h2l(magic_num);
    image_num = h2l(image_num);
    row_num = h2l(row_num);
    col_num = h2l(col_num);
    
    cout << "img num: " << image_num << " row_num: " << row_num << " col_num: " << col_num << endl;

    assert(fsize == (16 + image_num * col_num * row_num));
    data.resize(image_num, vector<double>(row_num * col_num));
    char* p = buffer + 16;
    for (int image_idx = 0; image_idx < image_num; image_idx++) {
        for (int r = 0; r < row_num; r++) {
            for (int c = 0; c < col_num; c++) {
                unsigned char t = p[0];
                data[image_idx][ r * row_num + c] = t;
                data[image_idx][ r * row_num + c] /= 255;
                p++;
            }
        }
    }
    
    cout << endl;
    fclose (fin);
    free (buffer);
}

void load_image_label(const char* filename, vector<int>& data) {
    FILE* fin = fopen(filename, "rb");
    fseek (fin , 0 , SEEK_END);
    int fsize = ftell(fin);
    rewind(fin);
    char* buffer = (char*) malloc (sizeof(char)*fsize);
    fread (buffer, 1, fsize, fin);
    
    uint32_t magic_num;
    uint32_t image_num;
    memcpy(&magic_num, buffer, 4);
    memcpy(&image_num, buffer+4, 4);
    magic_num = h2l(magic_num);
    image_num = h2l(image_num);
    data.resize(image_num);
    
    char* p = buffer + 8;
    assert(fsize == (8 + image_num));
    for (int i = 0; i < image_num; i++) {
        data[i] = p[i];
       // cout << "img label: " << data[i] << endl;
    }
}

class Neuron;
typedef vector<Neuron> Layer;
typedef vector<double> Instance;
typedef vector<double> TargetVal;

struct Conn {
    double weight;
    double delta_weight;
};

class Neuron {
private:
    vector<Conn> m_output_weights;
    int m_my_index;
    static double random_weight() { return rand() / double(RAND_MAX); }

    vector<double> m_delta_z;
    vector<double> m_a;
    vector<double> m_z;
    bool m_bias_flag;
    int m_cur_mini_batch_size;
    
    static double eta;
    static double alpha;

public:
    Neuron(uint32_t output_num, uint32_t index, bool bias_flag=false) {
        for (uint32_t i = 0; i < output_num; i++) {
            m_output_weights.push_back(Conn());
            m_output_weights.back().weight = random_weight();
            m_output_weights.back().delta_weight = 0;
        }
        m_my_index = index;
        m_bias_flag = bias_flag;
    }

    void reset_mini_batch_size(int mini_batch_size) {
        m_a.resize(mini_batch_size, 0);
        m_z.resize(mini_batch_size, 0);
        m_delta_z.resize(mini_batch_size, 0);
        m_cur_mini_batch_size = mini_batch_size;
    }

    void set_a(int i, double val) {
        assert(i >= 0 && i < m_cur_mini_batch_size);
        m_a[i] = val;
    }

    void set_z(int i, double val) {
        assert(i >= 0 && i < m_cur_mini_batch_size);
        m_z[i] = val;
    }

    double get_a(int i) const {
        assert(i >= 0 && i < m_cur_mini_batch_size);
        return m_bias_flag ? 1 : m_a[i];
    }

    void feed_forward(const Layer& prev_layer) {
        for (int ins_index = 0; ins_index < m_cur_mini_batch_size; ins_index ++) {
            double sum = 0.0;
            for (int n = 0; n < prev_layer.size() - 1; n++) {
                sum += (
                        prev_layer[n].get_a(ins_index) * prev_layer[n].m_output_weights[m_my_index].weight
                        );
            }

            //cout << "feed_forwad::" << sum << endl;
            sum += (prev_layer.back().m_output_weights[m_my_index].weight); // bias 
            m_z[ins_index] = sum;
            m_a[ins_index] = Neuron::activation(sum);
        }
    }

    static double activation(double x) {
        //return tanh(x);
        return 1.0/ (1 + exp(-x));
    }

    static double activation_derivative(double x) {
        //return 1 - tanh(x) * tanh(x);
        //return 1 - x * x;
        double f = 1.0/ (1 + exp(-x));
        return f * (1 - f);
    }

    double sum_dzw(const Layer& next_layer, const int ins_index) {
        double sum = 0.0;
        for (int i = 0; i < next_layer.size() - 1; i++) {
            sum += m_output_weights[i].weight * next_layer[i].m_delta_z[ins_index];
        }
        return sum;
    }

    void calc_output_gradients(const vector<TargetVal>& target_vals, int neuron_index) {
        assert(neuron_index == m_my_index);
        for (int ins_index = 0; ins_index < target_vals.size(); ins_index ++) {
            double delta = m_a[ins_index] - target_vals[ins_index][neuron_index];
            //m_delta_z[ins_index] = delta * Neuron::activation_derivative(m_z[ins_index]);
            m_delta_z[ins_index] = delta * Neuron::activation_derivative(m_a[ins_index]);
        }
    }

    void calc_hidden_gradients(Layer& next_layer) {
        for (int ins_index = 0; ins_index < m_cur_mini_batch_size; ins_index ++) {
            double dzw = sum_dzw(next_layer, ins_index);
            //cout << "calc_hidden_gradients::" << m_z[ins_index] << endl;
            //m_delta_z[ins_index] = dzw * Neuron::activation_derivative(m_z[ins_index]);
            m_delta_z[ins_index] = dzw * Neuron::activation_derivative(m_a[ins_index]);
        }
    }

    void update_input_weights(Layer& prev_layer) {
        for (int n = 0; n < prev_layer.size(); n++) {
            Neuron& neuron = prev_layer[n];
            double old_delta_w = neuron.m_output_weights[m_my_index].delta_weight;
            double new_delta_w = 0.0;
            for (int ins_index = 0; ins_index < m_cur_mini_batch_size; ins_index ++) {
                new_delta_w += (
                        neuron.get_a(ins_index) * m_delta_z[ins_index]    
                        );
            }
            new_delta_w *= eta;
            new_delta_w /= m_cur_mini_batch_size;
            new_delta_w += (alpha * old_delta_w);

            neuron.m_output_weights[m_my_index].delta_weight = new_delta_w;
            neuron.m_output_weights[m_my_index].weight -= new_delta_w;
        }
    }

    void print() {
        cout << "Neuron: " << m_my_index << " bias_flag: " << m_bias_flag << endl;
        cout << "m_a_z ";
        for (int i = 0; i < m_a.size(); i++)
            cout << m_a[i] << " " << m_z[i];
        cout << endl;
    }
};


double Neuron::eta = 0.5;    // overall net learning rate, [0.0..1.0]
double Neuron::alpha = 0;   // momentum, multiplier of last deltaWeight, [0.0..1.0]

class MLP {
public:
    MLP(std::vector<uint32_t> topo) {
        uint32_t layer_num = topo.size();
        for (int layer_index = 0; layer_index < layer_num; layer_index++) {
            m_layers.push_back(Layer());
            uint32_t output_num = (layer_index == layer_num - 1 ? 0 : topo[layer_index + 1]);
            
            for (int neuron_index = 0; neuron_index < topo[layer_index]; neuron_index ++) {
                m_layers.back().push_back(Neuron(output_num, neuron_index));
            }
            m_layers.back().push_back(Neuron(output_num, topo[layer_index], true)); // bias neuron
        }
    }

    void init_mini_batch(int mini_batch_size) {
        m_cur_mini_batch_size = mini_batch_size;
        for (int i = 0; i < m_layers.size(); i++) {
            Layer& cur_layer = m_layers[i];
            for (int neuron_index = 0; neuron_index < cur_layer.size(); 
                    neuron_index ++) {
                cur_layer[neuron_index].reset_mini_batch_size(mini_batch_size);
            }
        }
        m_loss.resize(mini_batch_size, 0);
    }

    void feed_input_layer(const vector<Instance>& mini_batch_instances) {
        for (int ins_index = 0; ins_index < mini_batch_instances.size(); ins_index++) {
            for (int neuron_index = 0; neuron_index < m_layers[0].size() - 1;
                    neuron_index++) {
                m_layers[0][neuron_index].set_a(
                        ins_index, mini_batch_instances[ins_index][neuron_index]);
            }
        }
    }

    void feed_forward(const vector<Instance>& mini_batch_instances) {
        feed_input_layer(mini_batch_instances);
        
        for (int layer_index = 1; layer_index < m_layers.size(); layer_index ++) {
            Layer& prev_layer = m_layers[layer_index - 1];
            for (int n = 0; n < m_layers[layer_index].size() - 1; n++) {
                m_layers[layer_index][n].feed_forward(prev_layer);
            }
        }
    }

    void compute_loss(const vector<TargetVal>& target_vals) {
        const Layer& output_layer = m_layers.back();
        for (int ins_index = 0; ins_index < m_cur_mini_batch_size; ins_index ++ ) {
            double sum = 0.0;
            for (int n = 0; n < output_layer.size() - 1; n++) {
                double delta = target_vals[ins_index][n] - output_layer[n].get_a(ins_index);
                sum += delta * delta;
            }
            m_loss[ins_index] = sum;
        }
    }

    double get_avg_loss() {
        double loss = 0;
        for (int i = 0; i < m_cur_mini_batch_size; i++) {
            loss += m_loss[i];
        }
        assert(m_cur_mini_batch_size != 0);
        return loss/m_cur_mini_batch_size;
    }

    void back_prop(const vector<TargetVal>& target_vals) {
        Layer& output_layer = m_layers.back();

        for (int n = 0; n < output_layer.size() - 1; ++n)
            output_layer[n].calc_output_gradients(target_vals, n);

        for (int i = m_layers.size() - 2; i > 0; i--) {
            Layer& hidden_layer = m_layers[i];
            Layer& next_layer = m_layers[i + 1];
           for (int n = 0; n < hidden_layer.size() - 1; n++) 
               hidden_layer[n].calc_hidden_gradients(next_layer);
        }

        for (int i = m_layers.size() - 1; i > 0; i--) {
            Layer& layer = m_layers[i];
            Layer& prev_layer = m_layers[i - 1];

            for (int n = 0; n < layer.size() - 1; n++)
                layer[n].update_input_weights(prev_layer);
        }
    }

    void next_mini_batch(const vector<Instance>& mini_batch_instances,
            const vector<TargetVal>& target_vals ) {
        init_mini_batch(mini_batch_instances.size());
        
        feed_forward(mini_batch_instances);
        compute_loss(target_vals);
        back_prop(target_vals);
    }

    void get_resuls(std::vector<TargetVal>& result) {
        for (int i = 0; i < m_cur_mini_batch_size; i++) {
            result.push_back(TargetVal());
            for (int j = 0; j < m_layers.back().size() - 1; j++)
                result.back().push_back(m_layers.back()[j].m_a[i]);
        }
    }

    void get_output_max(std::vector<int> & result) {
        Layer& output_layer = m_layers.back();
        for (int i = 0; i < m_cur_mini_batch_size; i++) {
            int max_n = 0;
            double max_a = output_layer[0].get_a(i);
            for (int n = 1; n < output_layer.size() - 1; n++) {
                if (output_layer[n].get_a(i) > max_a) {
                    max_n = n;
                    max_a = output_layer[n].get_a(i);
                }
            }
            result.push_back(max_n);
        }
    }

    void print() {
        cout << "layer num " << m_layers.size() << endl;
        for (int i = 0; i < m_layers.size() - 1; i++) {
            cout << "Layer:: " << i << endl;
            for (int n = 0; n < m_layers[i].size(); n++)
                m_layers[i][n].print();
        }
    }

    /*
    void static test() {
        cout << "test......" << endl;
        vector<unsigned> topology = {2, 2, 2};
        MLP mlp_trainer(topology);
        Layer& l0 = mlp_trainer.m_layers[0];
        Layer& l1 = mlp_trainer.m_layers[1];
        Layer& l2 = mlp_trainer.m_layers[2];

        l0[0].m_output_weights = {{0.15, 0}, {0.25, 0},};
        l0[1].m_output_weights = {{0.20, 0}, {0.30, 0},};
        l0[2].m_output_weights = {{0.35, 0}, {0.35, 0},};
        
        l1[0].m_output_weights = {{0.40, 0}, {0.50, 0}};
        l1[1].m_output_weights = {{0.45, 0}, {0.55, 0}};
        l1[2].m_output_weights = {{0.60, 0}, {0.60, 0}};

        vector<Instance> input = {{0.05, 0.10}};
        assert(input.size() == 1);
        mlp_trainer.init_mini_batch(input.size());
        mlp_trainer.feed_forward(input);
        

        double zh1 = 0.15 * 0.05 + 0.20 * 0.1 + 0.35;
        double zh2 = 0.25 * 0.05 + 0.30 * 0.1 + 0.35;

        double oh1 = 1.0 / (1 + exp(-zh1));
        double oh2 = 1.0 / (1 + exp(-zh2));

        double zo1 = 0.40 * oh1 + 0.45 * oh2 + 0.6;
        double zo2 = 0.50 * oh1 + 0.55 * oh2 + 0.6;

        double oo1 = 1.0/ (1+exp(-zo1));
        double oo2 = 1.0/ (1+exp(-zo2));
        
        assert(l2[0].m_a[0] == oo1);
        assert(l2[1].m_a[0] == oo2);

        vector<TargetVal> target = {{0.01, 0.99} };
        mlp_trainer.back_prop(target);

        double dzo1 = (oo1 - 0.01)*Neuron::activation_derivative(zo1);
        double dzo2 = (oo2 - 0.99)*Neuron::activation_derivative(zo2);
        assert(l2[0].m_delta_z[0] == dzo1);
        assert(l2[1].m_delta_z[0] == dzo2);

        double dzh1 = ( dzo1 * 0.40 + dzo2 * 0.50 ) * Neuron::activation_derivative(zh1);
        double dl1_outw_0 = dzo1 * oh1;
        assert(abs(l1[0].m_output_weights[0].weight-(0.40 - Neuron::eta * dl1_outw_0)) < 1e-6);
        cout << l1[0].m_output_weights[0].weight << endl;
        cout << l1[0].m_output_weights[1].weight << endl;
        cout << l1[1].m_output_weights[0].weight << endl;
        cout << l1[1].m_output_weights[1].weight << endl;

        cout << l0[0].m_output_weights[0].weight << endl;
        cout << l0[0].m_output_weights[1].weight << endl;
        cout << l0[1].m_output_weights[0].weight << endl;
        cout << l0[1].m_output_weights[1].weight << endl;

    }
    */

private:
    vector<Layer> m_layers;
    std::vector<double> m_loss;
    int m_cur_mini_batch_size;
};

int main() {
 
    const char* f_train_img_data = "data/train-images-idx3-ubyte";
    const char* f_train_img_label = "data/train-labels-idx1-ubyte";
    const char* f_test_img_data = "data/t10k-images-idx3-ubyte";
    const char* f_test_img_label = "data/t10k-labels-idx1-ubyte";

    vector<vector<double> > train_img_data;
    vector<vector<double> > test_img_data;
    vector<int> train_img_label;
    vector<int> test_img_label;

    load_image_data(f_train_img_data, train_img_data);
    load_image_label(f_train_img_label, train_img_label);
    load_image_data(f_test_img_data, test_img_data);
    load_image_label(f_test_img_label, test_img_label);

    vector<unsigned> topology = {784, 100, 10};
    
    MLP mlp_trainer(topology);

    const int mini_batch_size = 100;
    for (int epoch = 0; epoch < 10; epoch ++) {
        cout << train_img_data.size() << endl;
        vector<int> idx;
        for (int i = 0; i < train_img_data.size(); i++)
            idx.push_back(i);
        // obtain a time-based seed:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (idx.begin(), idx.end(), std::default_random_engine(seed));

        for (int i = 0; i < train_img_data.size(); i+= mini_batch_size) {
            vector<Instance> input;
            vector<TargetVal> label;
            //cout << "prepare data " << endl;
            for (int k = 0; k < mini_batch_size; k++) {
                int pos = idx[k+i];
                input.push_back(train_img_data[pos]);   
                label.push_back(TargetVal());
                label.back().resize(10, 0);
                label.back()[train_img_label[pos]] = 1;
            }
            mlp_trainer.next_mini_batch(input, label);
        }
        cout << "epoch " << epoch  << " loss " << mlp_trainer.get_avg_loss() << endl;
        
        mlp_trainer.init_mini_batch(test_img_data.size());
        mlp_trainer.feed_forward(test_img_data);
        vector<int> pred;
        mlp_trainer.get_output_max(pred);

        double true_num = 0;
        for (int s = 0; s < test_img_data.size(); s++) {
            if (test_img_label[s] == pred[s])
                true_num ++;
        }
        cout << "Accuracy " << true_num / test_img_data.size() << endl;
    }
    return 0;
}
