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

class Solution {
public:
    typedef vector<vector<bool> > vvbool;
    typedef vector<vector<int> > vvint;
    typedef vector<int> vint;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end(), cmp);
        int last = num[0];
        vector<int> candidates;
        candidates.push_back(0);
        vector<int> counts;
        counts.push_back(0);
        int cnt = 1;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] != last) {
                candidates.push_back(last);
                counts.push_back(cnt);
                last = num[i];
                cnt = 1;
            } else
                cnt++;
        }
        candidates.push_back(last);
        counts.push_back(cnt);
        
        vvbool dp(candidates.size(), vector<bool>(target+1, false));
        dp[0][0] = true;
        for (int i = 1; i < candidates.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (!dp[i-1][j])
                    continue;
                for (int k = 0, v = j; (k <= counts[i]) && (v <= target); 
                    k++, v+= candidates[i]) {
                    dp[i][v] = true;    
                }
            }
        }
        
        vvint ret;
        vint path;
        findPath(dp, candidates.size() - 1, candidates, counts, path, ret, target);
        return ret;
    }
    
    void findPath(vvbool &dp, int n, vint &candidates, vint &counts, vint &path, vvint& ret, int target) {
        if (target == 0) {
            if (path.size() > 0)
                ret.push_back(path);
            return;
        } else if (n == 0)
            return;
        
        if (!dp[n][target]) {
            findPath(dp, n-1, candidates, counts, path, ret, target);
            return;
        }
        int i = 0;
        for (; (i <= counts[n]) && (target >= 0) ; i++, target -= candidates[n]) {
            findPath(dp, n - 1, candidates, counts, path, ret, target);
            path.push_back(candidates[n]);
        }
        for (int j = 0; j < i; j++)
            path.pop_back();
    }
    static bool cmp(int i, int j) {
        return i > j;
    }
};
