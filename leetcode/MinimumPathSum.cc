/*
 * =====================================================================================
 *
 *       Filename:  MinimumPathSum.cc
 *
 *    Description:  
        Given a m x n grid filled with non-negative numbers, 
        find a path from top left to bottom right which 
        minimizes the sum of all numbers along its path.

        Note: You can only move either down or right at any point in time.


 *        Version:  1.0
 *        Created:  2013/7/26 12:25:05
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
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        if (m==0)
            return 0;
        int n = grid[0].size();
        vector<vector<int> > f(m, vector<int>(n, -1));
        return minPathSum(grid, f, 0, 0);
    }
    
    int minPathSum(vector<vector<int> > &grid, vector<vector<int> > &f, int m, int n) {
        if (f[m][n] != -1)
            return f[m][n];
        if (m == grid.size() - 1) {
            int ret = 0;
            for (int i = grid[0].size() - 1; i >= n; i--) {
                ret += grid[m][i];
                f[m][i] = ret;
            }
            return ret;
        }
        int ret = 0x7FFFFFFF;
        if (n < (grid[0].size() - 1))
            ret = minPathSum(grid, f, m, n+1);
        int t = minPathSum(grid, f, m+1, n);
        ret = ret < t ? ret : t;
        ret += grid[m][n];
        f[m][n] = ret;
        return ret;
    }
};
