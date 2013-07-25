/*
 * =====================================================================================
 *
 *       Filename:  SetMatrixZeros.cc
 *
 *    Description:  
        Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

        Follow up:
        Did you use extra space?
        A straight forward solution using O(mn) space is probably a bad idea.
        A simple improvement uses O(m + n) space, but still not the best solution.
        Could you devise a constant space solution?
 
 *
 *        Version:  1.0
 *        Created:  2013/7/23 20:29:16
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
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int m = matrix.size();
        if (m == 0)
            return;
        
        int n = matrix[0].size();
        bool* row = new bool[m];
        for (int i = 0; i < m; i++)
            row[i] = false;
        bool* col = new bool[n];
        for (int i = 0; i < n; i++)
            col[i] = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (row[i]) {
                matrix[i] = vector<int>(n, 0);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (col[i]) {
                for (int j = 0; j < m; j++){
                    matrix[j][i] = 0;
                }    
            }
        }
        delete []col;
        delete []row;
        
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int m = matrix.size();
        if (m == 0)
            return;
        
        int n = matrix[0].size();
        int row_flag = false;
        int col_flag = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                row_flag = true;
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                col_flag = true;
                break;                
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                matrix[i] = vector<int>(n, 0);
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        
        if (row_flag) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        
        if (col_flag) {
            matrix[0] = vector<int>(n, 0);
        }
    }
};

