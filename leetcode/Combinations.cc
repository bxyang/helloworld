/*
 * =====================================================================================
 *
 *       Filename:  Combinations.cc
 *
 *    Description:  
        Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

        For example,
        If n = 4 and k = 2, a solution is:

        [
          [2,4],
          [3,4],
          [2,3],
          [1,2],
          [1,3],
          [1,4],
        ]
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/23 15:11:00
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
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if ((n==0) || (k==0))
            return ret;
        if (n < k)
            return ret;
        ret = combine(n-1, k);
        if (k == 1) {
            ret.push_back(vector<int>(1, n));
            return ret;
        }
        vector<vector<int> > tmp = combine(n-1, k - 1);
        for (vector<vector<int> >::iterator it = tmp.begin(); it != tmp.end(); it++){
            it -> push_back(n);
            ret.push_back(*it);
        }
        return ret;
    }
};
 
