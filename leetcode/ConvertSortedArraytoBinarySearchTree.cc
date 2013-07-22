/*
 * =====================================================================================
 *
 *       Filename:  ConvertSortedArraytoBinarySearchTree.cc
 *
 *    Description: Given an array where elements are sorted in ascending order, convert it to a height balanced BST. 
 *
 *        Version:  1.0
 *        Created:  2013/7/21 21:35:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
        TreeNode* ret;
        if (start == end) {
            ret = new TreeNode(num[start]);
            return ret;
        }
        if (start > end)
            return NULL;        
        int mid = start + (end - start)/2;
        ret = new TreeNode(num[mid]);
        ret -> left = sortedArrayToBST(num, start, mid - 1);
        ret -> right = sortedArrayToBST(num, mid+1, end);
        return ret;        
    }
};
