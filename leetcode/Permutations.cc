/*
 * =====================================================================================
 *
 *       Filename:  Permutations.cc
 *
 *    Description:  
        Given a collection of numbers, return all possible permutations.

        For example,
        [1,2,3] have the following permutations:
        [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/31 22:11:58
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
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        permute(num, 0, ret);
        return ret;
    }
    
    void permute(vector<int> &num, int next, vector<vector<int> > &ret){
        if (next == num.size()) {
            ret.push_back(num);
        }
        
        for (int i = next; i < num.size(); i++) {
            swap(num[next], num[i]);
            permute(num, next + 1, ret);
            swap(num[next], num[i]);
        }    
    }
};

