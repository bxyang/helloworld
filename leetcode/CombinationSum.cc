/*
 * =====================================================================================
 *
 *       Filename:  CombinationSum.cc
 *
 *    Description:  
        Given a set of candidate numbers (C) and a target number (T), 
        find all unique combinations in C where the candidate numbers sums to T.

        The same repeated number may be chosen from C unlimited number of times.

        Note:

        All numbers (including target) will be positive integers.
        Elements in a combination (a1, a2, ? , ak) must be in non-descending order. (ie, a1 ? a2 ? ? ? ak).
        The solution set must not contain duplicate combinations.
        For example, given candidate set 2,3,6,7 and target 7, 
        A solution set is: 
        [7] 
        [2, 2, 3] 
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/2 11:02:35
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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> num;
        combinationSum(candidates, 0, num, ret, 0, target);
        return ret;
    }
    
    void combinationSum(vector<int> &candidates, int pos,
        vector<int>& num, vector<vector<int> > &ret, int sum, int target) {
        if (sum == target) {
            ret.push_back(num);
            return;
        } else if (sum > target) {
            return;
        }
        if (pos == candidates.size())
            return;
        int diff = target - sum;
        int n = diff / candidates[pos];
        for (int i = 0; i <= n; i++) {
            vector<int> tmp = vector<int>(i, candidates[pos]);
            num.insert(num.end(), tmp.begin(), tmp.end());
            combinationSum(candidates, pos+1, num, ret, sum + i*candidates[pos], target);
            for (int j = 0; j < i; j++)
                num.pop_back();            
        }
    }
};
class Solution {
public:
    typedef vector<vector<bool> > vvbool;
    typedef vector<vector<int> > vvint;
    typedef vector<int> vint;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int can_num = candidates.size();
        sort(candidates.begin(), candidates.end(), cmp);
        vector<vector<bool> > dp(can_num+1, vector<bool>(target+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= can_num; i++) {
            for (int j = 0; j <= target; j++) {
                if (!dp[i-1][j])
                    continue;
                for (int k = j; k <= target; k += candidates[i-1])
                    dp[i][k] = true;
            }
        }
        vvint ret;
        vint path;
        findPath(candidates, dp, can_num, target, ret, path);
        return ret;
    }
    
    void findPath(vint &candidates, vvbool &dp, int n, int target, vvint &ret, vint &path) {
        if (target == 0) {
            if (path.size() > 0)
                ret.push_back(path);
            return;
        } else if (n == 0){
            return;
        }
        if (!dp[n][target]) {
            findPath(candidates, dp, n-1, target, ret, path);
            return;
        }
        int i = 0;
        for (; target >= 0; target -= candidates[n-1], i++) {
            findPath(candidates, dp, n-1, target, ret, path);
            path.push_back(candidates[n-1]);
        }
        for (int j = 0; j < i; j++)
            path.pop_back();
    }
    
    static bool cmp(int i, int j) {
        return i > j;
    }
};
