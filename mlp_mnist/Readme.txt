1. mkdir data
2. download train/test data from http://yann.lecun.com/exdb/mnist/
   and extract them to data dir
3. g++ -ggdb --std=c++11 mlp_mnist.cc 
4. ./a.out

the code create a 784 * 100 * 10 three layer nn with mse loss,
after 10 epoch training, the Accuracy ont test dataset is about 
 
