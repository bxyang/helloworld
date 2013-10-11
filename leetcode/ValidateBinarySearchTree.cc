/*
 * =====================================================================================
 *
 *       Filename:  ValidateBinarySearchTree.cc
 *
 *    Description:  
        Given a binary tree, determine if it is a valid binary search tree (BST).

        Assume a BST is defined as follows:

        The left subtree of a node contains only nodes with keys less than the node's key.
        The right subtree of a node contains only nodes with keys greater than the node's key.
        Both the left and right subtrees must also be binary search trees.

 *
 *        Version:  1.0
 *        Created:  2013/7/26 11:09:36
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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return true;
        int minVal;
        int maxVal;
        return isValidBST(root, minVal, maxVal);
    }
    
    bool isValidBST(TreeNode* root, int& minVal, int& maxVal) {
        int leftMin;
        int leftMax;
        int rightMin;
        int rightMax;
        
        if ((root -> left == NULL) && (root -> right == NULL)) {
            minVal = root -> val;
            maxVal = root -> val;
            return true;
        }
        
        if (root -> left != NULL) {
            if(! isValidBST(root -> left, leftMin, leftMax))
                return false;
        }
        if (root -> right != NULL) {
            if(! isValidBST(root -> right, rightMin, rightMax))
                return false;
        }
        
        if (root -> left == NULL) {
            if (root -> val >= rightMin)
                return false;
            minVal = root -> val;
            maxVal = rightMax;
        } else if (root -> right == NULL) {
            if (root -> val <= leftMax)
                return false;
            minVal = leftMin;
            maxVal = root -> val;
        } else {
            if ((root -> val >= rightMin) || (root -> val <= leftMax))
                return false;
            minVal = leftMin;
            maxVal = rightMax;
        }
        return true;
    }
};


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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        inOrder(root, v);
        if (v.size() < 2)
            return true;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= v[i-1])
                return false;
        }
        return true;
    }
    
    void inOrder(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;
        inOrder(root -> left, v);
        v.push_back(root -> val);
        inOrder(root -> right, v);
    }
};
