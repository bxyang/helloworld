/*
 * =====================================================================================
 *
 *       Filename:  RecoverBinarySearchTree.cc
 *
 *    Description:  
        Two elements of a binary search tree (BST) are swapped by mistake.

        Recover the tree without changing its structure.

        Note:
        A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

 *        Version:  1.0
 *        Created:  2013/7/25 20:51:03
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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode* > nodes;
        InorderTraversal(root, nodes);
        if (nodes.size() < 2)
            return;
        vector<TreeNode* >::iterator it1 = nodes.begin();
        vector<TreeNode* >::iterator it2 = nodes.begin();
        it2++;
        vector<TreeNode* >::iterator p1 = nodes.end();
        vector<TreeNode* >::iterator p2 = nodes.end();
        for (; it2 != nodes.end(); it2++, it1++) {
            if ( ((*it1) -> val) > ((*it2) -> val) ){
                if (p1 == nodes.end())
                    p1 = it1;
                else {
                    p2 = it2;
                    break;
                }
            }
        }
        if (p1 == nodes.end())
            return;
        else {
            if (p2 == nodes.end()) {
                swap((*p1) -> val, (*(next(p1))) -> val);
            } else {
                swap((*p1) -> val, (*p2) -> val);
            }
        }
    }
    
    void InorderTraversal(TreeNode* root, vector<TreeNode* >& nodes) {
        if (root == NULL)
            return;
        if (root -> left != NULL)
            InorderTraversal(root -> left, nodes);
        nodes.push_back(root);
        if (root -> right != NULL)
            InorderTraversal(root -> right, nodes);
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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode* > nodes(3, (TreeNode*)NULL);
        //vector<TreeNode* > nodes;
        InorderTraversal(root, nodes);
        if (nodes[1] == NULL)
            return;
        else {
            swap(nodes[1] -> val, nodes[2] -> val);
        }
    }
    
    void InorderTraversal(TreeNode* root, vector<TreeNode* >& nodes) {
        if (root == NULL)
            return;
        if (root -> left != NULL)
            InorderTraversal(root -> left, nodes);
        if (nodes[0] == NULL) {
            nodes[0] = root;
        } else {
            if ( (nodes[0] -> val) > (root -> val)) {
                if (nodes[1] == NULL) {
                    nodes[1] = nodes[0];
                    nodes[2] = root;
                } else {
                    nodes[2] = root;
                }
            }
            nodes[0] = root;
        }
        if (root -> right != NULL)
            InorderTraversal(root -> right, nodes);
    }
};

