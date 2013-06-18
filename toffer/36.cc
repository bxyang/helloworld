/*
 * =====================================================================================
 *
 *       Filename:  36.cc
 *
 *    Description:  reverse pairs
 *
 *        Version:  1.0
 *        Created:  06/18/2013 03:00:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>

int inverse_pairs_size_core(int* data, int* copy, int start, int end) {
    assert((data != NULL) && (copy != NULL) && (start < end));
    if (end - start > 1) {
        int mid = (start + end)/2;
        int left_count = inverse_pairs_size_core(copy, data, start, mid);
        int right_count = 0;
        if (end > (mid + 1))
            right_count = inverse_pairs_size_core(copy, data, mid + 1, end);
        int ret = left_count + right_count;
        int p1 = mid;
        int p2 = end;
        int index_copy = end;
        while ((p1 >= start) && (p2 >= (mid + 1))) {
            if (data[p1] > data[p2]) {
                ret += (p2 - (mid + 1) + 1);
                copy[index_copy--] = data[p1--];
            }
            else {
                copy[index_copy--] = data[p2--];
            }
        }
        for (; p1 >= start; p1--)
            copy[index_copy--] = data[p1];
        for (; p2 >= (mid+1); p2--)
            copy[index_copy--] = data[p2];
        return ret;
    }
    else {
        int ret = 0;
        if(data[start] > data[end]) {
            ret = 1;
            copy[start] = data[end];
            copy[end] = data[start];
        }
        else {
            copy[start] = data[start];
            copy[end] = data[end];
        }
        return ret;
    }
}
int inverse_pairs_size(int* data, int length) {
    int* copy = new int[length];
    memcpy(copy, data, sizeof(int)*length);
    return inverse_pairs_size_core(data, copy, 0, length - 1);
}
int main() {
    int a[] = {7, 5, 6, 4, 1, 2, 3};
    assert(inverse_pairs_size(a, 7) == 17);
    return 0;
}
