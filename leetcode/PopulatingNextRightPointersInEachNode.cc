/*
 * =====================================================================================
 *
 *       Filename:  PopulatingNextRightPointersInEachNode.cc
 *
 *    Description:  
 *        Given a binary tree
 *
 *            struct TreeLinkNode {
 *              TreeLinkNode *left;
 *              TreeLinkNode *right;
 *              TreeLinkNode *next;
 *            }
 *        Populate each next pointer to point to its next right node. 
 *        If there is no next right node, the next pointer should be set to NULL.
 *
 *        Initially, all next pointers are set to NULL.
 *
 *        Note:
 *
 *        You may only use constant extra space.
 *        You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 *        For example,
 *        Given the following perfect binary tree,
 *
 *                 1
 *               /  \
 *              2    3
 *             / \  / \
 *            4  5  6  7
 *        After calling your function, the tree should look like:
 *
 *                 1 -> NULL
 *               /  \
 *              2 -> 3 -> NULL
 *             / \  / \
 *            4->5->6->7 -> NULL
 *         
 *
 *        Version:  1.0
 *        Created:  2013/6/30 18:39:18
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
        if ((root == NULL) || (root -> left == NULL) || (root -> right == NULL))
            return;
        root -> left -> next = root -> right;
        root -> right -> next = (root -> next == NULL ? NULL : root -> next -> left);
        connect(root -> left);
        connect(root -> right);
    }
};


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
        list<int> q2;
        root -> next = NULL;
        q1.push_back(root);
        q2.push_back(0);
        while(!q1.empty()) {
            TreeLinkNode* parent = q1.front();
            int level = q2.front();
            q1.pop_front();
            q2.pop_front();
            if (parent -> left == NULL) {
                break;
            }
            q1.push_back(parent -> left);
            q1.push_back(parent -> right);
            q2.push_back(level + 1);
            q2.push_back(level + 1);
            list<TreeLinkNode*>::iterator it1 = q1.begin();
            list<int>::iterator it2 = q2.begin();
            int last_level = (*it2);
            for (; next(it1, 1) != q1.end(); it1++, it2++) {
                if ((*it2) == (*(next(it2, 1))))
                    (*it1) -> next = (*(next(it1, 1)));
                else
                    (*it1) -> next = NULL;
            }
        }
    }
};


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
        int next_level_num = 2;
        while(!q1.empty()) {
            TreeLinkNode* parent = q1.front();
            q1.pop_front();
            now_level_num--;
            if (parent -> left == NULL)
                break;
            q1.push_back(parent -> left);
            q1.push_back(parent -> right);
            if (now_level_num == 0) {
                now_level_num = next_level_num;
                next_level_num *= 2;
                for (list<TreeLinkNode*>::iterator it = q1.begin(); 
                    next(it, 1) != q1.end(); it++) {
                    (*it) -> next = (*(next(it, 1)));        
                }
            }
        }
    }
};
