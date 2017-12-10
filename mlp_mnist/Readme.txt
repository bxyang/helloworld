1. mkdir data
2. download train/test data from http://yann.lecun.com/exdb/mnist/
   and extract them to data dir
3. g++ -ggdb --std=c++11 mlp_mnist.cc 
4. ./a.out

the code create a 784 * 100 * 10 three layer nn with mse loss,
after 5 epoch training, the Accuracy ont test dataset is about 



ref:
1. https://www.youtube.com/watch?v=KkwX7FkLfug&t=612s
2. http://www.millermattson.com/dave/?p=54
3. https://mattmazur.com/2015/03/17/a-step-by-step-backpropagation-example/
4. http://neuralnetworksanddeeplearning.com/chap1.html
5. http://neuralnetworksanddeeplearning.com/chap1.html

 
