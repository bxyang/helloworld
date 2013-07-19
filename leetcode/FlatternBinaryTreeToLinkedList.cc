/*
 * =====================================================================================
 *
 *       Filename:  FlatternBinaryTreeToLinkedList.cc
 *
 *    Description:  
 
        Given a binary tree, flatten it to a linked list in-place.

        For example,
        Given

                 1
                / \
               2   5
              / \   \
             3   4   6
        The flattened tree should look like:
           1
            \
             2
              \
               3
                \
                 4
                  \
                   5
                    \
                     6
        Hints:
        If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

 *
 *        Version:  1.0
 *        Created:  2013/7/17 22:37:05
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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return;
        flattenCore(root);
    }
    
    TreeNode* flattenCore(TreeNode *root) {
        if ((root->left == NULL) && (root->right == NULL))
            return root;
        if (root->left == NULL)
            return flattenCore(root->right);        
        if (root->right == NULL) {
            root->right = root->left;
            root-> left = NULL;
            return flattenCore(root->right);
        }
        TreeNode* left_tail = flattenCore(root->left);
        TreeNode* right_tail = flattenCore(root->right);
        left_tail->right = root->right;
        root->right = root->left;
        root-> left = NULL;
        return right_tail;
    }
};

