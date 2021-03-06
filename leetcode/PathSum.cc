/*
 * =====================================================================================
 *
 *       Filename:  PathSum.cc
 *
 *    Description:  
        Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

        For example:
        Given the below binary tree and sum = 22,
                      5
                     / \
                    4   8
                   /   / \
                  11  13  4
                 /  \      \
                7    2      1
        return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 
 *
 *        Version:  1.0
 *        Created:  2013/6/30 10:35:35
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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return false;
        }
        bool has_left = false;
        bool has_right = false;
        sum -= (root -> val);
        if ((sum == 0) && (root -> left == NULL) && (root -> right == NULL))
            return true;
        if (root -> left != NULL)
            has_left = hasPathSum(root -> left, sum);
        if (root -> right != NULL)
            has_right = hasPathSum(root -> right, sum);
        return (has_left || has_right);
    }
};

