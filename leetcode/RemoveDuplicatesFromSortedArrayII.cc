/*
 * =====================================================================================
 *
 *       Filename:  RemoveDuplicatesFromSortedArrayII.cc
 *
 *    Description:  
        Follow up for "Remove Duplicates":
        What if duplicates are allowed at most twice?

        For example,
        Given sorted array A = [1,1,1,2,2,3],

        Your function should return length = 5, and A is now [1,1,2,2,3].
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/29 11:47:31
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
        if (n<3)
            return n;
        int p1 = 1;
        int last = A[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] != last) {
                A[p1] = A[i];
                last = A[i];
                count = 1;
                p1++;
            } else if (count < 2) {
                A[p1] = A[i];
                count++;
                p1++;
            }
        }
        return p1;
    }
};
