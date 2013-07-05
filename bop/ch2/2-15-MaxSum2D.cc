/*
 * =====================================================================================
 *
 *       Filename:  2-15-MaxSum2D.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/2013 10:28:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cstdio>

int max_sum1(int* data, int row_num, int col_num) {
    int ret = 0x80000000;
    int** part_sum = (int**)(new int[row_num+1]);
    part_sum[0] = new int[col_num+1];
    for (int i = 0; i <= col_num; i++)
        part_sum[0][i] = 0;
    for (int i = 1; i <= row_num; i++) {
        part_sum[i] = new int[col_num + 1];
        part_sum[i][0] += 0;
        for (int j = 1; j <= col_num; j++) {
            part_sum[i][j] = part_sum[i-1][j] + part_sum[i][j-1] - 
                part_sum[i-1][j-1] + ( *(data + (i-1) * col_num + j - 1));
        }
    }
    for (int r_min = 1; r_min <= row_num; r_min++) {
        for (int r_max = r_min; r_max <= row_num; r_max++) {
            for (int c_min = 1; c_min <= col_num; c_min++) {
                for (int c_max = c_min; c_max <= col_num; c_max++) {
                    int tmp = part_sum[r_max][c_max] - part_sum[r_min - 1][c_max] -
                        part_sum[r_max][c_min - 1] + part_sum[r_min - 1][c_min - 1];
                    ret = (ret > tmp) ? ret : tmp;
                }
            }
        }
    }
    return ret;
}


int main () {
    int data[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ret = max_sum1(data, 3, 3);
    printf("%d\n", ret);
    return 0;
}
