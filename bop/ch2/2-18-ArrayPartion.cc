/*
 * =====================================================================================
 *
 *       Filename:  2-18-ArrayPartion.cc
 *
 *    Description:  partion the 2N-size array to two N-size array, so that the two array sum
 *                  are closest
 *
 *        Version:  1.0
 *        Created:  07/07/2013 08:55:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstdio>
using namespace std;


void partion_array1(int* data, int n) {
    long long sum = 0;
    int twice_n = n << 1;
    int* p = data;
    for (int i = 0; i < twice_n; i++)
        sum += *(p++);
    long long half_sum = sum >> 1;
    vector<vector<long long> > sum_heap(n+1);
    for (int i = 1; i <= n; i++)
        make_heap(sum_heap[i].begin(), sum_heap[i].begin());
    sum_heap[0] = vector<long long>(1, 0);
    for (int i = 0; i < twice_n; i++) {
        int k = (i < n) ? (i - 1) : (n - 1);
        for (int j = k; j >= 0; j--) {
            for (vector<long long>::iterator it = sum_heap[j].begin();
                    it != sum_heap[j].end(); it++) {
                sum_heap[j+1].push_back((*it) + data[i]);
                push_heap(sum_heap[j+1].begin(), sum_heap[j+1].end());
            }
        }
    }
    long long len = sum_heap[n].size();
    printf("size=%lld\n", len);
    for (; len >= 0; len--) {
        pop_heap(sum_heap[n].begin(), sum_heap[n].end());
        long long t = sum_heap[n].back();
        if (t <= half_sum) {
            printf("closest half_sum=%lld\n", t);
            break;
        }
        sum_heap[n].pop_back();
    }
}

void partion_array2(int* data, int n) {
    long long sum = 0;
    int twice_n = n << 1;
    int* p = data;
    for (int i = 0; i < twice_n; i++)
        sum += *(p++);
    long long half_sum = sum >> 1;
    vector<vector<bool> > sum_flag(n+1, vector<bool>((sum >> 1) + 1, false));
    sum_flag[0][0] = true;
    for (int i = 0; i < twice_n; i++) {
        int k = (i < n) ? i : n;
        for (int j = k; j > 0; j--) {
            for (int v = 1; v <= half_sum; v++) {
                if ( (v >= data[i]) && (sum_flag[j-1][v-data[i]]) )
                    sum_flag[j][v] = true;
            }
        }
    }
    for (long long v = half_sum; v >= 0; v--) {
        if (sum_flag[n][v])
            printf("closest half_sum=%lld\n", v);
            break;
    }
}


int main() {
    int data[10] = {1, 5, 7, 8, 9, 6, 3, 11, 20, 17};
    partion_array1(data, 5);
    partion_array2(data, 5);
    return 0;
}
