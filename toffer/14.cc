/*
 * =====================================================================================
 *
 *       Filename:  14.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/03/2013 04:49:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cassert>


int partion(int* data, int n, bool (*func)(int)) {
    int left = -1;
    for (int i = 0; i < n; i++) {
        if (func(data[i])) {
            int t = data[i];
            data[i] = data[++left];
            data[left] = t;
        }
    }
    return left;
}

bool is_odd(int v) {
    if (v & 0x1)
        return true;
    return false;
} 

int main() {
    int data[] = {1, 2, 3, 4, 5};
    assert(partion(data, 1, is_odd) == 0);
    assert(partion(data + 1, 1, is_odd) == -1);
    assert(partion(data, 5, is_odd) == 2);
    return 0;
}
