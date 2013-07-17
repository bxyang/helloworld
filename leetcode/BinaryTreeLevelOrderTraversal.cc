/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeLevelOrderTraversal.cc
 *
 *    Description:
 
        Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

        For example:
        Given binary tree {3,9,20,#,#,15,7},

            3
           / \
          9  20
            /  \
           15   7
        return its level order traversal as:

        [
          [3],
          [9,20],
          [15,7]
        ]

 *
 *        Version:  1.0
 *        Created:  2013/7/17 9:47:04
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (root == NULL)
            return ret;
        queue<pair<TreeNode*, int> > q;
        q.push(pair<TreeNode*, int>(root, 0));
        int last_level = -1;
        vector<int> tmp;
        while(!q.empty()) {
            pair<TreeNode*, int> node = q.front();
            q.pop();
            if ((node.second != last_level) && (tmp.size() != 0)) {
                ret.push_back(tmp);
                tmp.clear();
                last_level = node.second;
            }
            tmp.push_back(node.first -> val);
            if (node.first -> left != NULL)
                q.push(pair<TreeNode*, int>(node.first -> left, node.second + 1));
            if (node.first -> right != NULL)
                q.push(pair<TreeNode*, int>(node.first -> right, node.second + 1));
        }
        ret.push_back(tmp);
        return ret;  
    }
};

