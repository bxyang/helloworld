/*
 * =====================================================================================
 *
 *       Filename:  3Sum.cc
 *
 *    Description:  
        Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
        Find all unique triplets in the array which gives the sum of zero.

        Note:

        Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
        The solution set must not contain duplicate triplets.
            For example, given array S = {-1 0 1 2 -1 -4},

            A solution set is:
            (-1, 0, 1)
            (-1, -1, 2)
 *
 *        Version:  1.0
 *        Created:  2013/7/28 13:22:06
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
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int len = num.size();
        vector<vector<int> > ret;
        if (len == 0)
            return ret;
        int last = num[0] - 1;
        for (int i = 0; i <= len - 3; i++) {
            if (num[i] == last)
                continue;
            vector<vector<int> > tmp = twoSum(num, i+1, len-1, 0-num[i]);
            if (tmp.size() > 0) {
                ret.insert(ret.end(), tmp.begin(), tmp.end());
            }
            last = num[i];
        }
        return ret;
    }
    
    vector<vector<int> > twoSum(vector<int> & num, int start, int end, int target) {
        vector<vector<int> > ret;
        while (start < end){
            int val = num[start] + num[end];
            if (val < target)
                start++;
            else if (val > target)
                end--;
            else{
                ret.push_back({-target, num[start], num[end]});
                int s_prev = num[start];
                int e_prev = num[end];
                while (start < end) {
                    if (num[start] == s_prev)
                        start++;
                    else
                        break;
                }
                
                while (start < end) {
                    if(num[end] == e_prev)
                        end--;
                    else
                        break;
                }
            }
        }
        return ret;
    }
};

