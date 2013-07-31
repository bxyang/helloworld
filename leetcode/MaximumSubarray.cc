/*
 * =====================================================================================
 *
 *       Filename:  MaximumSubarray.cc
 *
 *    Description:  
        Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

        For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
        the contiguous subarray [4,-1,2,1] has the largest sum = 6.

        More practice:
        If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach,
        which is more subtle.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/31 12:16:27
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
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
            return 0;
        int ret = A[0];
        int last = A[0];
        for (int i = 1; i < n; i++) {
            if (last < 0)
                last = A[i];
            else
                last = last + A[i];
            ret = ret > last - ret : last;
        }
        return ret;
    }
};

