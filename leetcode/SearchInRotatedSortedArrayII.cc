/*
 * =====================================================================================
 *
 *       Filename:  SearchInRotatedSortedArrayII.cc
 *
 *    Description:  
        Follow up for "Search in Rotated Sorted Array":
        What if duplicates are allowed?

        Would this affect the run-time complexity? How and why?

        Write a function to determine if a given target is in the array.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/1 15:50:29
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
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int key = A[mid];
            if (key == target)
                return true;
            if (key > A[left]) {
                if (key > target) {
                    if(-1 != bi_search(A, left, mid - 1, target) )
                        return true;
                    left = mid + 1;
                } else {
                    left = mid + 1;
                }
            } else if (key < A[left]) {
                if (key > target) {
                    right = mid - 1;
                } else {
                    if (-1 != bi_search(A, mid+1, right, target) )
                        return true;
                    right = mid - 1;
                }
            } else {
                if (key == A[right]) {
                    left += 1;
                    right -= 1;
                } else if (key < A[right]) {
                    if(-1 == bi_search(A, mid + 1, right, target))
                        return false;
                    else
                        return true;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
    
    int bi_search(int A[], int start, int end, int target){
        while (start <= end) {
            int mid = start + (end - start)/2;
            int key = A[mid];
            if (target == key)
                return mid;
            else if (target > key)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};
