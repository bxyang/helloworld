/*
 * =====================================================================================
 *
 *       Filename:  SumRootToLeafNumbers.cc
 *
 *    Description:
        Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

        An example is the root-to-leaf path 1->2->3 which represents the number 123.

        Find the total sum of all root-to-leaf numbers.

        For example,

            1
           / \
          2   3
        The root-to-leaf path 1->2 represents the number 12.
        The root-to-leaf path 1->3 represents the number 13.

        Return the sum = 12 + 13 = 25.
 *
 *
 *        Version:  1.0
 *        Created:  2013/6/28 22:31:43
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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        traverseTree(root, 0, sum);
        return sum;
    }
    
    void traverseTree(TreeNode *root, int i, int& sum) {
        if (root == NULL)
            return;
        i = i*10 + root -> val;
        if ((root -> left == NULL) && (root -> right == NULL)) {
            sum += i;
            return;
        }
        if (root -> left != NULL)
            traverseTree(root -> left, i, sum);
        if (root -> right != NULL)
            traverseTree(root -> right, i, sum);
    }
};











