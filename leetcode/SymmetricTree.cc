/*
 * =====================================================================================
 *
 *       Filename:  SymmetricTree.cc
 *
 *    Description:  
        Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

        For example, this binary tree is symmetric:

            1
           / \
          2   2
         / \ / \
        3  4 4  3
        But the following is not:

            1
           / \
          2   2
           \   \
           3    3
        Note:
        Bonus points if you could solve it both recursively and iteratively.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/1 17:29:48
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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return true;
        list<TreeNode* > next = {root -> left, root -> right};
        return isSymmetric(next);
    }
    
    bool isSymmetric(list<TreeNode* > &nodes) {
        bool flag = true;
        list<TreeNode* >::iterator it1 = nodes.begin();
        list<TreeNode* >::iterator it2 = nodes.end();
        it2--;
        int i = 0;
        int n = nodes.size();
        while (i < n) {
                i++;
            if ((*it1 == NULL) && (*it2 == NULL)) {
                it1++;
                it2--;
                continue;
            }
            if ( (*it1 == NULL) || (*it2 == NULL) )
                return false;
            if ( (*it1) -> val != (*it2) -> val)
                return false;
            flag = false;
            nodes.push_back((*it1) -> left);
            nodes.push_back((*it1) -> right);
            it1++;
            it2--;
        }
        if (flag)
            return true;
        for (int i = 0; i < n; i++)
            nodes.pop_front();
        return isSymmetric(nodes);
    }
};
