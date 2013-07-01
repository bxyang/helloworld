/*
 * =====================================================================================
 *
 *       Filename:  PopulatingNextRightPointersInEachNodeII.cc
 *
 *    Description:  
 *        Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 *        What if the given tree could be any binary tree? Would your previous solution still work?
 *
 *        Note:
 *
 *        You may only use constant extra space.
 *        For example,
 *        Given the following binary tree,
 *
 *                 1
 *               /  \
 *              2    3
 *             / \    \
 *            4   5    7
 *        After calling your function, the tree should look like:
 *
 *                 1 -> NULL
 *               /  \
 *              2 -> 3 -> NULL
 *             / \    \
 *            4-> 5 -> 7 -> NULL
 *         
 *
 *        Version:  1.0
 *        Created:  2013/6/30 21:43:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return;
        list<TreeLinkNode*> q1;
        root -> next = NULL;
        q1.push_back(root);
        int now_level_num = 1;
        int next_level_num = 0;
        while(!q1.empty()) {
            TreeLinkNode* parent = q1.front();
            q1.pop_front();
            now_level_num--;
            if (parent -> left != NULL) {
                next_level_num ++;
                q1.push_back(parent -> left);
            }
            if (parent -> right != NULL) {
                next_level_num ++;
                q1.push_back(parent -> right);    
            }            
            if (now_level_num == 0) {
                now_level_num = next_level_num;
                next_level_num = 0;
                for (list<TreeLinkNode*>::iterator it = q1.begin(); 
                    next(it, 1) != q1.end(); it++) {
                    (*it) -> next = (*(next(it, 1)));        
                }
            }
        }
    }
};

