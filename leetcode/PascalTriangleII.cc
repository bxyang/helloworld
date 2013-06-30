/*
 * =====================================================================================
 *
 *       Filename:  PascalTriangleII.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/6/29 23:51:08
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
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (rowIndex == 0)
            return vector<int>(1, 1);
        if (rowIndex == 1)
            return vector<int>(2, 1);
        vector<int> ret(2, 1);
        for (int i = 2; i <= rowIndex; i++) {
            vector<int> tmp(i+1, 1);
            int n = i / 2;
            for (int j = 1; j <= n; j++) {
                tmp[j] = ret[j-1] + ret[j];
                tmp[i - j] = tmp[j];
            }
            ret = tmp;
        }
        return ret;
    }
};

