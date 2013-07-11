/*
 * =====================================================================================
 *
 *       Filename:  Search2DMatrix.cc
 *
 *    Description:
        Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

        Integers in each row are sorted from left to right.
        The first integer of each row is greater than the last integer of the previous row.
        For example,

        Consider the following matrix:

        [
          [1,   3,  5,  7],
          [10, 11, 16, 20],
          [23, 30, 34, 50]
        ]
        Given target = 3, return true.
 
 *
 *        Version:  1.0
 *        Created:  2013/7/11 11:35:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row_num = matrix.size();
        if (row_num == 0)
            return false;
        int col_num = matrix[0].size();
        int start = 0;
        int end = row_num - 1;
        while (start < (end - 1)) {
            int mid = start + (end - start) / 2;
            int key = matrix[mid][0];
            if (key == target)
                return true;
            else if (key > target)
                end = mid - 1;
            else
                start = mid;
        }
        int search_row;
        if (start == end)
            search_row = start;
        else {
            int key = matrix[end][0];
            if (key < target)
                search_row = end;
            else if (key == target)
                return true;
            else
                search_row = start;
        }
        start = 0;
        end = col_num - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int key = matrix[search_row][mid];
            if (key == target)
                return true;
            else if (key > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};

