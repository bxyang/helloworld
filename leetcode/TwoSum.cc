/*
 * =====================================================================================
 *
 *       Filename:  TwoSum.cc
 *
 *    Description:  
        Given an array of integers, find two numbers such that they add up to a specific target number.

        The function twoSum should return indices of the two numbers such that they add up to the target, 
        where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

        You may assume that each input would have exactly one solution.

        Input: numbers={2, 7, 11, 15}, target=9
        Output: index1=1, index2=2
 *
 *        Version:  1.0
 *        Created:  2013/7/10 15:02:30
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
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tmp(numbers);
        sort(tmp.begin(), tmp.end());
        int j = numbers.size() - 1;
        int i = 0;
        int a[2];
        while (i < j) {
            int sum = tmp[i] + tmp[j];
            if (sum == target) {
                a[0] = tmp[i];
                a[1] = tmp[j];
                break;
            } else if (sum < target)
                i++;
            else
                j--;
        }
        int k = 0;
        vector<int> ret(2, 0);
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
            k++;
            if ((a[0] == (*it)) && (!ret[0]))
                ret[0] = k;
            else if (a[1] == (*it))
                ret[1] = k;
        }
        if (ret[0] > ret[1])
            swap(ret[0], ret[1]);
        return ret;
    }
};
