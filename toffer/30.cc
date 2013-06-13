/*
 * =====================================================================================
 *
 *       Filename:  30.cc
 *
 *    Description:  top k-least number
 *
 *        Version:  1.0
 *        Created:  06/13/2013 02:03:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<utility>
#include<cstdlib>
#include<cstdio>
#include<cassert>

void max_heapify(int* arr, int n, int pos);

void build_max_heap(int* arr, int n) {
    for (int pos = n / 2 - 1; pos >=0; pos--) {
        max_heapify(arr, n, pos);
    }
}

void max_heapify(int* arr, int n, int pos) {
    int parent = pos;
    int max = pos;
    while (parent < n) {
        int lch = (parent<<1) + 1;
        if (lch >= n)
            break;
        if (arr[lch] > arr[max])
            max = lch;
        int rch = lch + 1;
        if ((rch < n) && (arr[rch] > arr[max]))
            max = rch;
        if (max == parent)
            break;
        std::swap(arr[max], arr[parent]);
        parent = max;
    }
}

void find_k_least(int* arr, int n, int k) {
    assert((arr != NULL) && (n > 0));
    if (k >= n)
        return;
    build_max_heap(arr, k);
    for (int i = k; i < n; i++) {
        if(arr[0] > arr[i]) {
            std::swap(arr[0], arr[i]);
            max_heapify(arr, k, 0);
        }
    }
}

int main() {
    int data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    const int k = 4;
    find_k_least(data, 10, k);
    for (int i = 0; i < k; i++)
        printf("%d ", data[i]);
    printf("\n");
}
