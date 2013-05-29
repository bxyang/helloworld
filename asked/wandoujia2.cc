/*
 * =====================================================================================
 *
 *       Filename:  wandoujia3.cc
 *
 *    Description:  print subset of set
 *
 *        Version:  1.0
 *        Created:  05/29/2013 07:42:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cstdio>
#include<cstring>

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
    memcpy(tmp, result, sizeof(int) * rlen);
    print_subset(data + 1, len - 1, result, rlen);
    // restore result
    memcpy(result, result, sizeof(int) * rlen);
    result[rlen] = data[0];
    print_subset(data + 1, len - 1, result, rlen + 1);   
}

int main() {
	int data[3] = {1, 2, 3};
	int result[3];
	print_subset(data, 3, result, 0);
	return 0;
}
