/*
 * =====================================================================================
 *
 *       Filename:  RotateImage.cc
 *
 *    Description:  
        You are given an n x n 2D matrix representing an image.

        Rotate the image by 90 degrees (clockwise).

        Follow up:
        Could you do this in-place?
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/31 21:41:29
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
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        if (n < 2)
            return;        
        int start_r = 0;
        int start_c = 0;
        int end_c = matrix.size() - 1;
        while (start_r < n/2 ) {
            for (; start_c < end_c; start_c ++) {
                int lr = start_r;
                int lc = start_c;
                int last = matrix[lr][lc];
                do {
                    int nr = lc;
                    int nc = n - lr - 1;
                    int tmp = matrix[nr][nc];
                    matrix[nr][nc] = last;
                    last = tmp;
                    lr = nr;
                    lc = nc;
                } while ((lr != start_r) || (lc != start_c));
            }
            start_r += 1;
            start_c = start_r;
            end_c --;
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        if (n < 2)
            return;        
        int start_r = 0;
        int start_c = 0;
        int end_c = matrix.size() - 1;
        while (start_r < n/2 ) {
            for (; start_c < end_c; start_c ++) {
                int tmp = matrix[start_r][start_c];
                matrix[start_r][start_c] = matrix[n-start_c-1][start_r];
                matrix[n-start_c-1][start_r] = matrix[n-start_r-1][n-start_c-1];
                matrix[n-start_r-1][n-start_c-1] = matrix[start_c][n-start_r-1];
                matrix[start_c][n-start_r-1] = tmp;
            }
            start_r += 1;
            start_c = start_r;
            end_c --;
        }
    }
};

