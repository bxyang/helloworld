/*
 * =====================================================================================
 *
 *       Filename:  ToTheMax.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/8/25 16:13:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cstdlib>
#include<cstdio>

int max_subarray(int* arr, int n);
int main() {
    int data[100][100];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &data[i][j]);
        }
    }
    int top2down_col_sum[100][100];
    for (int j = 0; j < N; j++)
        top2down_col_sum[0][j] = data[0][j];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++)
            top2down_col_sum[i][j] = top2down_col_sum[i-1][j] + data[i][j];
    }
    int max_sum = 0x80000000;
    for (int j = 0; j < N; j++) {
        int t = max_subarray(top2down_col_sum[j], N);
        max_sum = max_sum > t ? max_sum : t;
    }
    int* arr = new int[N];
    for (int i = 1; i < N; i++) {
        int t = max_subarray(data[i], N);
        max_sum = max_sum > t ? max_sum : t;
        for (int j = i+1; j < N; j++) {
            for (int k = 0; k < N; k++)
                arr[k] = top2down_col_sum[j][k] - top2down_col_sum[i-1][k];
            int t = max_subarray(arr, N);
            max_sum = max_sum > t ? max_sum : t;
        }
    }
    printf("%d\n", max_sum);
    return 0;
}

int max_subarray(int* arr, int n) {
    int sum = arr[0];
    int ret = sum; 
    for (int i = 1; i < n; i++) {
        if (sum < 0)
            sum = arr[i];
        else
            sum += arr[i];
        ret = ret > sum ? ret : sum;
    }
    return ret;
}
