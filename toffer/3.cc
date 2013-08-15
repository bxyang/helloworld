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

/*  
#include<cassert>
#include<cstdlib>
#include<cstdio>
  
bool matrix_search(int** data, int row_start, int row_end, int col_start, int col_end, int target ){
    if ((data == NULL) || (row_start > row_end) || (col_start > col_end)) {
        return false;
    }
    while ((row_start <= row_end) && (col_start <= col_end)) {
        int mid_row = row_start + (row_end - row_start)/2;
        int key_left = data[mid_row][col_start];
        int key_right = data[mid_row][col_end];
        if (target == key_left)
               return true;
        else if (target < key_left)
               row_end = mid_row - 1;
        else if (target > key_right) 
               row_start = mid_row + 1;
        else if (target == key_right)
                return true;
        else {
             int tmp_start = col_start;
             int tmp_end= col_end;
             while (tmp_start < tmp_end) {
                 int mid_col = tmp_start + (tmp_end - tmp_start)/2;
                 int key_col = data[mid_row][mid_col];
                 if (target == key_col)
                     return true;
                 else if (target > key_col)
                     tmp_start =  mid_col + 1;
                 else
                     tmp_end = mid_col;       
             }
             return matrix_search(data, mid_row+1, row_end, col_start, tmp_end-1, target ) || 
                             matrix_search(data, row_start, mid_row-1, tmp_end,  col_end,  target );
        }
    }
    return false;
}
  
int main() {
    int row_num;
    int col_num;
    int target;
    bool flag  =true;
    while (scanf("%d %d", &row_num, &col_num) != EOF) {
        scanf("%d", &target);
        if (! flag)
            printf("\n"); 
        else
            flag = false;
        int** data =(int**) new int[row_num];
        for (int i = 0; i < row_num; i++) {
            data[i] = new int[col_num];
            for (int j = 0; j < col_num; j++) {
                scanf("%d", &data[i][j]);
            }
        }
        if (matrix_search(data, 0, row_num-1,0, col_num-1, target))
            printf("Yes");
        else
            printf("No");
    } 
    return 0;
}
 
 */
