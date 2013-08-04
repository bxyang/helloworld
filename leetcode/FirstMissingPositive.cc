/*
 * =====================================================================================
 *
 *       Filename:  FirstMissingPositive.cc
 *
 *    Description:  
        Given an unsorted integer array, find the first missing positive integer.

        For example,
        Given [1,2,0] return 3,
        and [3,4,-1,1] return 2.

        Your algorithm should run in O(n) time and uses constant space.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/4 16:14:50
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
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while (i < n) {
            if (A[i] == (i+1))
                i++;
            else if ((0 < A[i]) && (A[i] <= n) && (A[A[i] - 1] != A[i]))
                swap(A[i], A[A[i]-1]);
            else
                i++;
        }
        i = 0;
        while (i < n) {
            if (A[i] != (i+1))
                return i+1;
            else
                i++;
        }
        return n+1;
    }
};
