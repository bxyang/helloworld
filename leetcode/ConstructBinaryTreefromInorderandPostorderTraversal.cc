/*
 * =====================================================================================
 *
 *       Filename:  ConstructBinaryTreefromInorderandPostorderTraversal.cc
 *
 *    Description:  
        Given inorder and postorder traversal of a tree, construct the binary tree.

        Note:
        You may assume that duplicates do not exist in the tree.

 *
 *        Version:  1.0
 *        Created:  2013/7/22 15:02:28
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeCore(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode *buildTreeCore(vector<int> &inorder, int in_start, int in_end,
            vector<int> &postorder, int post_start, int post_end) {
        if (in_start > in_end)
            return NULL;
        int val = postorder[post_end];
        TreeNode* root = new TreeNode(val);
        int i = in_start;
        for (; i <= in_end; i++) {
            if (inorder[i] == val)
                break;
        }
        if (i>in_end){
            return NULL; // throw exception;
        }
        
        root -> left = buildTreeCore(inorder, in_start, i - 1, 
                                postorder, post_start, post_start + (i-1-in_start));
        root -> right = buildTreeCore(inorder, i+1, in_end, 
                                postorder, post_end - 1 - (in_end - i - 1), post_end - 1);
        return root;
    }
};

