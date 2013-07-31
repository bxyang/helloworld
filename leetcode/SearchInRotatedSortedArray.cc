/*
 * =====================================================================================
 *
 *       Filename:  SearchInRotatedSortedArray.cc
 *
 *    Description:  
        Suppose a sorted array is rotated at some pivot unknown to you beforehand.

        (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

        You are given a target value to search. If found in the array return its index, otherwise return -1.

        You may assume no duplicate exists in the array.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/30 17:49:12
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
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int key = A[mid];
            if (key == target)
                return mid;
            if (mid == left) {
                if (A[right] == target)
                    return right;
                else
                    return -1;
            }
            
            if (A[left] < key) {
                if (key > target) {
                    int ret = bi_search(A, left, mid - 1, target);
                    if (ret != -1)
                        return ret;
                }
                left = mid + 1;
            } else {
                if (key < target) {
                    int ret = bi_search(A, mid+1, right, target);
                    if (ret != -1)
                        return ret;
                }
                right = mid - 1;
            }
        }
        return -1;
    }
    
    int bi_search(int A[], int start, int end, int target) {
        if (start > end)
            return -1;
        int left = start;
        int right = end;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int key = A[mid];
            if (key == target)
                return mid;
            else if (key > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};
