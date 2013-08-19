/*
 * =====================================================================================
 *
 *       Filename:  TrapRainWater.cc
 *
 *    Description:  
        Given n non-negative integers representing an elevation map where the width of each bar is 1, 
        compute how much water it is able to trap after raining.

        For example, 
        Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

        The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
        In this case, 6 units of rain water (blue section) are being trapped. 
        Thanks Marcos for contributing this image!
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/19 20:49:47
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
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n - 1;
        while (left < right){
            if (A[left+1] < A[left])
                break;
            left++;
        }
        while (right > left) {
            if (A[right-1] < A[right])
                break;
            right--;
        }
        if (left == right)
            return 0;
        return trap_core(A, left, right);
    }
    
    int trap_core(int A[], int left, int right) {
        if (left >= (right - 1))
            return 0;
        int low_height = A[left] < A[right] ? A[left] : A[right];
        int i = left + 1;
        int max = i;
        for (; i < right; i++) {
            if (A[i] > A[max])
                max = i;
        }
        if (A[max] > low_height)
            return trap_core(A, left, max) + trap_core(A, max, right);
        int area = (right - left - 1)*low_height;
        i = left + 1;
        for (i; i < right; i++)
            area -= A[i];
        return area;
    }
};
