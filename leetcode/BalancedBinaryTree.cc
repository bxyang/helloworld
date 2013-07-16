/*
 * =====================================================================================
 *
 *       Filename:  BalancedBinaryTree.cc
 *
 *    Description:  
        Given a binary tree, determine if it is height-balanced.

        For this problem, a height-balanced binary tree is defined as a binary tree in 
        which the depth of the two subtrees of every node never differ by more than 1.

 *
 *        Version:  1.0
 *        Created:  2013/7/14 12:31:13
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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return true;
        int height = 0;
        return isBalancedCore(root, height);
    }
    
    bool isBalancedCore(TreeNode *root, int& height) {
        if ((root -> left == NULL) && (root -> right == NULL)) {
            height = 1;
            return true;
        }
        int left_height = 0;
        int right_height = 0;
        if (root -> left != NULL)
            if(! isBalancedCore(root -> left, left_height))
                return false;
        if (root -> right != NULL)
            if(! isBalancedCore(root -> right, right_height))
                return false;
        if (abs(left_height - right_height) <= 1) {
            height = (left_height > right_height) ? left_height : right_height;
            height ++;
            return true;    
        }
        else
            return false;
    }
};

