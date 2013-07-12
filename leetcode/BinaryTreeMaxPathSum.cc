/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeMaxPathSum.cc
 *
 *    Description:  
        Given a binary tree, find the maximum path sum.

        The path may start and end at any node in the tree.

        For example:
        Given the below binary tree,

               1
              / \
             2   3
        Return 6.

 *        Version:  1.0
 *        Created:  2013/7/12 12:12:26
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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return (maxPathSumCore(root))[1];
    }
    
    vector<int> maxPathSumCore(TreeNode *root) {
        // ret[0] max suffix
        // ret[1] max subvector
        vector<int> ret(2);            
        if ((root -> left == NULL) && (root -> right == NULL))
            ret = vector<int>(2, root -> val);
        else if ((root -> left != NULL) && (root -> right != NULL)) {
            vector<int> left_ret = maxPathSumCore(root -> left);
            vector<int> right_ret = maxPathSumCore(root -> right);
            int max_suffix = (left_ret[0] > right_ret[0]) ? left_ret[0] : right_ret[0];
            ret[0] = (max_suffix <= 0) ? (root -> val) : ((root -> val) + max_suffix);
            ret[1] = max (left_ret[1], 
                max(right_ret[1], 
                    max(root -> val, 
                        max(left_ret[0] + root -> val, 
                            max(right_ret[0] + root -> val,
                                left_ret[0] + right_ret[0] + root -> val)))));
        }
        else if (root -> left == NULL) {
            vector<int> right_ret = maxPathSumCore(root -> right);
            ret[0] = (right_ret[0] <= 0) ? (root -> val) : ((root -> val) + right_ret[0]);;
            ret[1] = max(right_ret[1], 
                max(root -> val, right_ret[0] + root -> val));
        } else {
            vector<int> left_ret = maxPathSumCore(root -> left);
            ret[0] = (root -> val) > (root -> val + left_ret[0]) ? 
                root -> val : (root -> val + left_ret[0]);
            ret[1] = max(left_ret[1], 
                max(root -> val, left_ret[0] + root -> val));     
        }
        return ret;
    }
};

