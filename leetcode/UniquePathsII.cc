/*
 * =====================================================================================
 *
 *       Filename:  UniquePathsII.cc
 *
 *    Description:  
        Follow up for "Unique Paths":

        Now consider if some obstacles are added to the grids. How many unique paths would there be?

        An obstacle and empty space is marked as 1 and 0 respectively in the grid.

        For example,

        There is one obstacle in the middle of a 3x3 grid as illustrated below.

        [
          [0,0,0],
          [0,1,0],
          [0,0,0]
        ]
        The total number of unique paths is 2.
 *
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/26 14:49:16
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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;
        if (obstacleGrid[m-1][n-1] == 1)
            return 0;
        vector<vector<int> > f(m, vector<int>(n, -1)); 
        return uniquePathsWithObstaclesCore(obstacleGrid, f, 0, 0);
    }
    
    int uniquePathsWithObstaclesCore(vector<vector<int> > &obstacleGrid, 
        vector<vector<int> > &f, int lm, int ln) {
        int m_end = obstacleGrid.size()-1;
        int n_end = obstacleGrid[0].size()-1;
        if ((lm == m_end) && (ln == n_end))
            return 1;
        if (f[lm][ln] != -1)
            return f[lm][ln];
        if (obstacleGrid[lm][ln] == 1) {
            f[lm][ln] = 0;
            return 0;
        }
        int ret = 0;
        if (lm == m_end) {
            ret = uniquePathsWithObstaclesCore(obstacleGrid, f, lm, ln + 1); 
        } else if (ln == n_end) {
            ret = uniquePathsWithObstaclesCore(obstacleGrid, f, lm+1, ln); 
        } else {
            ret = uniquePathsWithObstaclesCore(obstacleGrid, f, lm, ln + 1);
            ret += uniquePathsWithObstaclesCore(obstacleGrid, f, lm+1, ln); 
        }
        f[lm][ln] = ret;
        return ret;
    }
};

