/*
 * =====================================================================================
 *
 *       Filename:  BiSearch.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2013 06:41:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<assert.h>

int bi_search(int* p, int n, int key) {
    assert(p != NULL);
    if (n <= 0)
        return -1;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (p[mid] == key)
            return mid;
        else if (p[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    const int len = 5;
    int a[len] = {1, 2, 3, 4, 5};
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            assert(bi_search(a, i + 1, j + 1) == j);
        }
    }
    assert(bi_search(a, 0, 0) == -1);
    assert(bi_search(a, len, 0) == -1);
    assert(bi_search(a, len - 1, 0) == -1);
    return 0;
}
