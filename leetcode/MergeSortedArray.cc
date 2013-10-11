/*
 * =====================================================================================
 *
 *       Filename:  MergeSortedArray.cc
 *
 *    Description:  
        Given two sorted integer arrays A and B, merge B into A as one sorted array.

        Note:
        You may assume that A has enough space to hold additional elements from B. 
        The number of elements initialized in A and B are m and n respectively.
 *
 *
 *        Version:  1.0
 *        Created:  2013/9/11 16:55:10
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
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k = m + n - 1;
        m = m - 1;
        n = n - 1;
        while ((m >= 0) && (n >= 0)) {
            if (A[m] > B[n]) {
                A[k--] = A[m];
                m--;
            } else {
                A[k--] = B[n];
                n--;
            }
        }
        if (n < 0)
            return;
        while (n >= 0)
            A[k--] = B[n--];
    }
};

