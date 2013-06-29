/*
 * =====================================================================================
 *
 *       Filename:  PascalTriangle.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/6/29 23:35:37
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
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        for (int i = 1; i <= numRows; i++) {
            vector<int> tmp(i, 1);
            if (i != 2) {
                int n = i / 2;
                for (int j = 1; j <= n; j++) {
                    tmp[j] = ret[i-2][j-1] + ret[i-2][j];
                    tmp[i- j - 1] = tmp[j];
                }
            };
            ret.push_back(tmp);
        }
        return ret;
    }
};

