/*
 * =====================================================================================
 *
 *       Filename:  UniquePaths.cc
 *
 *    Description:  
 *
        A robot is located at the top-left corner of a m x n grid 
        (marked 'Start' in the diagram below).

        The robot can only move either down or right at any point in time. 
        The robot is trying to reach the bottom-right corner of the grid 
        (marked 'Finish' in the diagram below).

        How many possible unique paths are there?
 *
 *        Version:  1.0
 *        Created:  2013/7/26 14:20:28
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
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > f(m, vector<int>(n, -1));
        return uniquePaths(0, 0, f, m-1, n-1);
    }
    
    int uniquePaths(int lm, int ln, vector<vector<int> > &f, int m_end, int n_end) {
        if ((lm == m_end) || (ln == n_end))
            return 1;
        if (f[lm][ln] != -1)
            return f[lm][ln];
        int ret = 0;
        ret = uniquePaths(lm, ln + 1, f, m_end, n_end);
        ret += uniquePaths(lm+1, ln, f, m_end, n_end);
        f[lm][ln] = ret;
        return ret;
    }
};
