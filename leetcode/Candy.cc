/*
 * =====================================================================================
 *
 *       Filename:  Candy.cc
 *
 *    Description:
        There are N children standing in a line. Each child is assigned a rating value.

        You are giving candies to these children subjected to the following requirements:

        Each child must have at least one candy.
        Children with a higher rating get more candies than their neighbors.
        What is the minimum candies you must give?
 *
 *
 *        Version:  1.0
 *        Created:  2013/10/23 11:19:14
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
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = ratings.size();
        vector<int> nums(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1])
                nums[i] = nums[i-1] + 1; 
        }
        
        int cnt = nums[n - 1];
        for (int i = n - 1; i >= 1; i--) {
            if (ratings[i-1] > ratings[i]) {
                nums[i-1] = max(nums[i-1], nums[i] + 1);
            }
            cnt += nums[i-1];
        }
        
        return cnt;
    }
};

