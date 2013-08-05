/*
 * =====================================================================================
 *
 *       Filename:  RemoveDuplicatesFromSortedArray.cc
 *
 *    Description:  
        Given a sorted array, remove the duplicates in place such that
        each element appear only once and return the new length.

        Do not allocate extra space for another array, 
        you must do this in place with constant memory.

        For example,
        Given input array A = [1,1,2],

        Your function should return length = 2, and A is now [1,2].
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/4 21:33:20
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
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1)
            return 0;
        int last = A[0];
        int p = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] != last) {
                A[p++] = A[i];
                last = A[i];
            }
        }
        return p;
    }
};

