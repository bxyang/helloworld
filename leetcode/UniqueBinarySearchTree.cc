/*
 * =====================================================================================
 *
 *       Filename:  UniqueBinarySearchTree.cc
 *
 *    Description:  
        Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

        For example,
        Given n = 3, there are a total of 5 unique BST's.

           1         3     3      2      1
            \       /     /      / \      \
             3     2     1      1   3      2
            /     /       \                 \
           2     1         2                 3
         
 *        Version:  1.0
 *        Created:  2013/7/25 22:33:11
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
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return numTreesCore(1, n);
    }
    
    int numTreesCore(int start, int end) {
        if (start >= end)
            return 1;
        int ret = 0;
        for (int i = start; i <= end; i++) {
            ret += numTreesCore(start, i-1) * numTreesCore(i+1, end);
        }
        return ret;
    }
};

