/*
 * =====================================================================================
 *
 *       Filename:  SearchInsertPosition.cc
 *
 *    Description:
        Given a sorted array and a target value, return the index if the target is found. 
        If not, return the index where it would be if it were inserted in order.

        You may assume no duplicates in the array.

        Here are few examples.
        [1,3,5,6], 5 ¡ú 2
        [1,3,5,6], 2 ¡ú 1
        [1,3,5,6], 7 ¡ú 4
        [1,3,5,6], 0 ¡ú 0
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/10 11:26:34
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
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target == A[mid])
                return mid;
            else if (target > A[mid])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

