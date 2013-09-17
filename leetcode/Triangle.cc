/*
 * =====================================================================================
 *
 *       Filename:  Triangle.cc
 *
 *    Description:  
        Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
        For example, given the following triangle

        [
             [2],
            [3,4],
           [6,5,7],
          [4,1,8,3]
        ]
        The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 *        Version:  1.0
 *        Created:  2013/6/29 22:25:37
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
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        vector<int> dp(triangle[n-1]);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + (dp[j] < dp[j+1] ? dp[j] : dp[j+1]);
        }
        return dp[0];
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return minimumTotalCore(triangle, 0, 0);        
    }
    
    int minimumTotalCore(vector<vector<int> > &triangle, int r, int c) {
        if (r == (triangle.size() - 1))
            return triangle[r][c];
        int left_sum = minimumTotal(triangle, r + 1, c);
        int right_sum = minimumTotal(triangle, r + 1, c + 1);
        return left_sum > right_sum ? (left_sum + triangle[r][c]) : (right_sum + triangle[r][c]);
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, int> mininum;
        return minimumTotalCore(triangle, mininum, 0, 0);
        
    }
    
    int minimumTotalCore(vector<vector<int> > &triangle, 
            map<string, int>& mininum, int r, int c) {
        if (r == (triangle.size() - 1))
            return triangle[r][c];
        string key = "a" + string(1, r + '0') + "+" + string(1, c + '0');
        if (mininum.find(key) != mininum.end())
            return mininum.at(key);
        int left_sum = minimumTotalCore(triangle, mininum, r + 1, c);
        int right_sum = minimumTotalCore(triangle, mininum, r + 1, c + 1);
        int ret = left_sum < right_sum ? (
            left_sum + triangle[r][c]) : (right_sum + triangle[r][c]); 
        
        mininum.insert(pair<string, int>(key, ret));
        return ret;
    }
};
