/*
 * =====================================================================================
 *
 *       Filename:  2-10-MaxMin.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/03/2013 02:40:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cassert>
#include<utility>

void find_min_max(int* data, int n, int& min_num, int& max_num) {
    if ((data == NULL) || (n < 1))
        return;
    if (n == 1) {
        min_num = data[0];
        max_num = data[0];
        return;
    }
    max_num = (data[0] > data[1]) ? data[0] : data[1];
    min_num = (data[0] < data[1]) ? data[0] : data[1];
    int i = 3;
    for (; i < n; i += 2) {
        int n_min = data[i-1];
        int n_max = data[i];
        if (n_min > n_max)
            std::swap(n_min, n_max);
        if (min_num > n_min)
            min_num = n_min;
        if (max_num < n_max)
            max_num = n_max;
    }
    if (i != n)
        return;
    if (data[n-1] > max_num) {
        max_num = data[n-1];
        return;
    }
    if (data[n-1] < min_num) {
        min_num = data[n-1];
        return;
    }
}

void find_min_max_recursive(int* data, int start, int end, int& min_num, int& max_num) {
    if (start == end) {
        min_num = data[start];
        max_num = data[start];
        return;
    }
    int mid = start + (end - start) >> 1;
    int n_min[2];
    int n_max[2];
    find_min_max_recursive(start, mid, n_min[0], n_max[0]);
    find_min_max_recursive(mid + 1, end, n_min[1], n_max[1]);
    if (n_min[0] < n_min[1])
        min_num = n_min[0];
    else
        min_num = n_min[1];
    if (n_max[0] > n_max[1])
        max_num = n_max[0];
    else
        max_num = n_max[1];
}

int main() {
    return 0;
}
