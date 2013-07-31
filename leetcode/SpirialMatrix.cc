/*
 * =====================================================================================
 *
 *       Filename:  SpirialMatrix.cc
 *
 *    Description:  
        Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

        For example,
        Given the following matrix:

        [
         [ 1, 2, 3 ],
         [ 4, 5, 6 ],
         [ 7, 8, 9 ]
        ]
        You should return [1,2,3,6,9,8,7,4,5].
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/31 11:21:11
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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int end_r = matrix.size() - 1;
        if (end_r == -1)
            return ret;
        int start_r = 0;
        int start_c = 0;
        int end_c = matrix[0].size() - 1;
        while ( (start_r <= end_r) && (start_c <= end_c)) {
            for (int i = start_c; i <= end_c; i++)
                ret.push_back(matrix[start_r][i]);
            
            if ((start_r + 1) < end_r) {
                for (int i = start_r + 1; i < end_r; i++)
                    ret.push_back(matrix[i][end_c]);
            }
            
            if (start_r < end_r) {
                for (int i = end_c; i >= start_c; i--)
                    ret.push_back(matrix[end_r][i]);
            }
            
            if ( ((start_r + 1) < end_r) && (start_c < end_c)) {
                for (int i = end_r - 1; i > start_r; i--)
                    ret.push_back(matrix[i][start_c]);
            }
            
            start_r += 1;
            end_r -= 1;
            start_c += 1;
            end_c -= 1;
        }
        return ret;
    }
};

