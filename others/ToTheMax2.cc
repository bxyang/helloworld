/*
 * =====================================================================================
 *
 *       Filename:  ToTheMax2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/8/25 17:55:22
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
   
    int max_sum[100][100];
    for (int j = 0; j < N; j++) {
        max_sum[0][j] = max_subarray(top2down_col_sum[j], N);
        max_sum[j][j] = max_subarray(data[j], N);
    }
    
    int* arr = new int[N];
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = 0; k < N; k++)
                arr[k] = top2down_col_sum[j][k] - top2down_col_sum[i-1][k];
            max_sum[i][j] = max_subarray(arr, N);
        }
    }
    int top2down_max[100];
    top2down_max[0] = max_sum[0][0];
    for (int i = 1; i < N; i++) {
        int t = top2down_max[i-1];
        for (int j = 0; j <= i; j++)
            t = t > max_sum[j][i] ? t : max_sum[j][i];
        top2down_max[i] = t;
    }

    int down2top_max[100];
    down2top_max[N-1] = max_sum[N-1][N-1];
    for (int i = N-2; i >= 0; i--) {
        int t = down2top_max[i+1];
        for (int j = i+1; j < N; j++)
            t = t > max_sum[i][j] ? t : max_sum[i][j];
        down2top_max[i] = t;
    }

    int max_matrix_sum = 0x80000000;
    for (int i = 0; i <= N - 1; i++) {
        int t = top2down_max[i] + down2top_max[i+1];
        if (t >= max_matrix_sum)
            printf("%d\n", i);
        max_matrix_sum = max_matrix_sum > t ? max_matrix_sum : t;
    }

    printf("%d\n", max_matrix_sum);
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
