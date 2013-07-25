/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeZigzagLevelOrderTraversal.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/22 14:33:09
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (root == NULL)
            return ret;
        queue<TreeNode* > qu;
        qu.push(root);
        TreeNode* last = root;
        TreeNode* cur;
        bool flag = false;
        vector<int> tmp;
        while (! qu.empty()) {
            TreeNode* node;
            node = qu.front();
            qu.pop();
            tmp.push_back(node -> val);
            if (node -> left != NULL) {
                qu.push(node -> left);
                cur = node -> left;
            }
            if (node -> right != NULL) {
                qu.push(node -> right);
                cur = node -> right;
            }
            if (node == last) {
                if (flag)
                    reverse(tmp.begin(), tmp.end());
                ret.push_back(tmp);
                tmp.clear();
                last = cur;
                flag = (! flag);
            }
        }
        if (tmp.size() > 0)
            ret.push_back(tmp);
        return ret;
    }
};

