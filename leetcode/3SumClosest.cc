/*
 * =====================================================================================
 *
 *       Filename:  3SumClosest.cc
 *
 *    Description:  
        Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
        Return the sum of the three integers. You may assume that each input would have exactly one solution.

            For example, given array S = {-1 2 1 -4}, and target = 1.

            The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/28 21:13:58
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
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        if (len<3)
            return 0x7FFFFFFF;
        sort(num.begin(), num.end());
        len -= 2;
        int dist = 0x7FFFFFFF;
        int ret;
        for (int i = 0; i < len; i++) {
            int tmp_sum = nearestSum(num, i+1, num.size() - 1, target - num[i]) + num[i];
            int tmp_dist = abs(tmp_sum - target);
            if(tmp_dist < dist) {
                ret = tmp_sum;
                dist = tmp_dist;
            }
        }
        return ret;
    }
    
    int nearestSum(vector<int> &num, int start, int end, int target) {
        int ret;
        if (start >= end)
            return ret;
        int dist = 0x7FFFFFFF;
        while(start < end) {
            int tmp = num[start] + num[end];
            int tmp_dist = abs(target-tmp);
            if (tmp_dist < dist) {
                dist = tmp_dist;
                ret = tmp;
            }
            if (tmp == target) {
                ret = tmp;
                return ret;
            } else if (target > tmp) {
                start++;
            } else {
                end--;
            }
        }
        return ret;        
    }
};

