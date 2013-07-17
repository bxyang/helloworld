/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeInorderTraversal.cc
 *
 *    Description:  
 
        Given a binary tree, return the inorder traversal of its nodes' values.

        For example:
        Given binary tree {1,#,2,3},

           1
            \
             2
            /
           3
        return [1,3,2].

        Note: Recursive solution is trivial, could you do it iteratively?

 *
 *        Version:  1.0
 *        Created:  2013/7/17 11:09:35
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (root == NULL)
            return ret;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while ( (p != NULL) || (!st.empty()) ) {
            while (p != NULL) {
                st.push(p);
                p = p -> left;
            }
            if (st.empty()){
                return ret;
            }
            p = st.top();
            ret.push_back(p -> val);
            st.pop();
            p = p -> right;
        }
        return ret;
    }
};

