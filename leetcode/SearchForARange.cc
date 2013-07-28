/*
 * =====================================================================================
 *
 *       Filename:  SearchForARange.cc
 *
 *    Description:  
        Given a sorted array of integers, find the starting and ending position of a given target value.

        Your algorithm's runtime complexity must be in the order of O(log n).

        If the target is not found in the array, return [-1, -1].

        For example,
        Given [5, 7, 7, 8, 8, 10] and target value 8,
        return [3, 4].
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/27 12:11:48
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
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n - 1;
        vector<int> ret(2, -1);
        while (left < right) {
            int mid = left + (right - left)/2;
            if (A[mid] > target)
                right = mid - 1;
            else if (A[mid] < target)
                left = mid + 1;
            else {
                int l = searchLeft(A, left, mid - 1, target);
                int r = searchRight(A, mid + 1, right, target);
                ret[0] = l;
                if (l == -1)
                    ret[0] = mid;
                ret[1] = r;
                if (r == -1)
                    ret[1] = mid;
                return ret;
            }
        }
        if (A[left] == target) {
            ret[0] = left;
            ret[1] = left;
        }
        return ret;
    }
    
    int searchRight(int A[], int start, int end, int target) {
        if (start > end)
            return -1;
        int left = start;
        int right = end;
        while (left < (right - 1)) {
            int mid = left + (right - left)/2;
            if (A[mid] > target)
                right = mid - 1;
            else if (A[mid] < target)
                left = mid + 1;
            else
                left = mid;
        }
        if (A[right] == target)
            return right;
        if (A[left] == target)
            return left;
        return -1;
    }
    
    int searchLeft(int A[], int start, int end, int target) {
        int left = start;
        int right = end;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (A[mid] > target)
                right = mid - 1;
            else if (A[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (A[left] == target)
            return left;
        return -1;
    }
};
