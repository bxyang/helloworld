/*
 * =====================================================================================
 *
 *       Filename:  RemoveElement.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/2 11:33:26
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
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; i++) {
            if (A[i] != elem)
                continue;        
            while ((n > 0) && A[n-1] == elem)
                n--;
            if ((n-1) < i)
                return n;
            swap(A[i], A[n-1]);
            n--;
        }
        return n;
    }
};

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((A == NULL) || (n < 1))
            return 0;
        return merge_partion(A, 0, n-1, elem);
    }
    
    int merge_partion(int A[], int left, int right, int elem) {
        if (left == right) {
            return A[left] == elem ? left : (left+1);
        }
        
        int mid = left + (right - left)/2;
        
        int p1 = merge_partion(A, left, mid, elem);
        int p2 = merge_partion(A, mid+1, right, elem);
        if (p1 == (mid+1))
            return p2;
        if (p2 == mid+1)
            return p1;
        merge(A, p1, p2-1, mid-p1+1);
        return p1 + ((p2-1) - (mid+1) + 1);
    }
    
    void merge(int A[], int left, int right, int n) {
        reverse(A, left, left+n-1);
        reverse(A, left+n, right);
        reverse(A, left, right);
    }
    
    void reverse(int A[], int left, int right) {
        while (left < right) {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    }
};
