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

