/*
 * =====================================================================================
 *
 *       Filename:  3.cc
 *
 *    Description:  matrix search:
 *                  every row is ascendly ordered, 
 *                  every column is ascendly ordered
 *
 *        Version:  1.0
 *        Created:  05/29/2013 10:06:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cassert>
#include<cstdlib>

void matrix_search(int** data, int row_len, int col_len,
    int key, int& row_ret, int& col_ret) {
    row_ret = -1;
    col_ret = -1;
    if ((data == NULL) || (row_len < 1) || (col_len < 1))
        return;
    int row_start = 0;
    int col_end = col_len - 1;
    while ((row_start < row_len) && (col_end > -1)) {
        // data[row_start][col_end]
        int n = *((int*)data + row_start * col_len + col_end);
        if (key == n) {
            row_ret = row_start;
            col_ret = col_end;
            return;
        }
        if (key > n)
            row_start++;
        else
            col_end--;
    }
}

int main() {
    int a[3][5] = {
                    {1, 2, 3, 4, 5},
                    {6, 7, 8, 9, 10},
                    {11, 12, 13, 14, 15}
                  };
    int row_ret = -2;
    int col_ret = -2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            matrix_search((int**)a, 3, 5, a[i][j], row_ret, col_ret);
            assert((row_ret == i) && (col_ret == j));
        }
    }
    matrix_search((int**)a, 3, 5, 0, row_ret, col_ret);
    assert((row_ret == -1) && (col_ret == -1));
    matrix_search((int**)a, 3, 5, 16, row_ret, col_ret);
    assert((row_ret == -1) && (col_ret == -1));
    return 0;
}
