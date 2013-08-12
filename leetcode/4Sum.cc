/*
 * =====================================================================================
 *
 *       Filename:  4Sum.cc
 *
 *    Description:  
        Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
        Find all unique quadruplets in the array which gives the sum of target.

        Note:

        Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
        The solution set must not contain duplicate quadruplets.
            For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

            A solution set is:
            (-1,  0, 0, 1)
            (-2, -1, 1, 2)
            (-2,  0, 0, 2)
 *
 *        Version:  1.0
 *        Created:  2013/8/12 17:24:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

class Solution {
    typedef vector<vector<int> > vv_int;
    typedef vector<int> v_int;
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vv_int ret;
        if (num.size() < 4)
            return ret;
        sort(num.begin(), num.end());
        int num_len = num.size();
        int last1 = num[0] - 1;
        for (int i = 0; i < (num_len - 3); i++) {
            if (last1 == num[i])
                continue;
            last1 = num[i];
            int last2 = num[i+1] - 1;
            for (int j = i + 1; j < (num_len - 2); j++) {
                if (last2 == num[j])
                    continue;
                last2 = num[j];
                twoSum(num, j+1, num[i], num[j], target, ret);
            }
        }
    }
    
    
    void twoSum(v_int &num, int start, int n1, int n2, int target, vv_int &ret) {
        target = target - n1 - n2;
        int p1 = start;
        int p2 = num.size() - 1;
        while (p1 < p2) {
            int key = num[p1] + num[p2];
            if (key > target)
                p2--;
            else if (key < target)
                p1++;
            else {
                ret.push_back({n1, n2, num[p1], num[p2]});
                int last1 = num[p1];
                int last2 = num[p2];
                while ((last1 == num[p1]) && (p1 < p2))
                    p1++;
                while ((last2 == num[p2]) && (p1 < p2))
                    p2--;               
            }
        }
    }
};
