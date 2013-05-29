#include<cstdio>


void print_subset(int* data, int len, int* result, int rlen) {
    if (len == 0){
        // print result
        for (int i = 0; i < rlen; i++) {
            printf("%d ", result[i]);
        }        
        printf("\n");        
        return;
    }
    // copy result
    int* tmp = new int[rlen];
    for (int i = 0; i < rlen; i++) {
        tmp[i] = result[i];
    }
    print_subset(data + 1, len - 1, result, rlen);
    // restore result
    for (int i = 0; i < rlen; i++) {
        result[i]  = tmp[i];
    }
    result[rlen] = data[0];
    print_subset(data + 1, len - 1, result, rlen + 1);   
}

int main() {
	int data[3] = {1, 2, 3};
	int result[3];
	print_subset(data, 3, result, 0);
	return 0;
}
