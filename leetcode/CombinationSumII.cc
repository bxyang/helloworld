/*
 * =====================================================================================
 *
 *       Filename:  CombinationSumII.cc
 *
 *    Description:  
        Given a collection of candidate numbers (C) and a target number (T), 
        find all unique combinations in C where the candidate numbers sums to T.

        Each number in C may only be used once in the combination.

        Note:

        All numbers (including target) will be positive integers.
        Elements in a combination (a1, a2, ? , ak) must be in non-descending order. (ie, a1 ? a2 ? ? ? ak).
        The solution set must not contain duplicate combinations.
        For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
        A solution set is: 
        [1, 7] 
        [1, 2, 5] 
        [2, 6] 
        [1, 1, 6] 
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/2 11:55:09
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
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> sol;
        sort(num.begin(), num.end());
        combinationSum2(num, 0, sol, 0, target, ret);
        return ret;
    }
    
    void combinationSum2(vector<int>& candidates, int pos, 
        vector<int> &sol, int sum, int target, vector<vector<int> > &ret) {
        if (sum == target) {
            ret.push_back(sol);
            return;
        } else if (sum > target) {
            return;
        }
        
        if (pos == candidates.size())
            return;
        int i = pos + 1;
        for (; i < candidates.size(); i++) {
            if (candidates[i] != candidates[pos])
                break;
        }
        
        i = i - pos;
        int n = (target - sum)/candidates[pos];
        n = (n<i)?n:i;
        for (int j = 0; j <= n; j++) {
            vector<int> tmp(j, candidates[pos]);
            sol.insert(sol.end(), tmp.begin(), tmp.end());
            combinationSum2(candidates, pos + i, sol, sum + candidates[pos]*j, target, ret);
            for (int k = 0; k < j; k++)
                sol.pop_back();
        }
    }
};

