/*
 * =====================================================================================
 *
 *       Filename:  ConstructBinaryTreefromPreorderandInorderTraversal.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/8/17 13:29:22
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, preorder.size() - 1);
    }
    
    TreeNode *buildTree(vector<int> &preorder, int pre_start, int pre_end,
        vector<int> &inorder, int in_start, int in_end) {
        if (pre_start > pre_end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int key = preorder[pre_start];
        int i = in_start;
        for (; i <= in_end; i++) {
            if (inorder[i] == key)
                break;
        }
        if (i > in_end)
            return NULL;
        root -> left = buildTree(preorder, pre_start + 1, pre_start + i - in_start,
                        inorder, in_start, i-1);
        root -> right = buildTree(preorder, pre_start + i - in_start + 1, pre_end,
                        inorder, i+1, in_end);
        return root;
    }
};
