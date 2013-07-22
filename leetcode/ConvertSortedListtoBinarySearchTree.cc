/*
 * =====================================================================================
 *
 *       Filename:  ConvertSortedListtoBinarySearchTree.cc
 *
 *    Description: Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST. 
 *
 *        Version:  1.0
 *        Created:  2013/7/21 22:18:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = 0;
        ListNode* p = head;
        while (p != NULL) {
            p = p -> next;
            n++;
        }
        return sortedListToBSTCore(head, n);
    }
    
    TreeNode *sortedListToBSTCore(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
            return NULL;
        TreeNode* ret = NULL;
        if (n == 1) {
            ret = new TreeNode(head -> val);
            return ret;
        }
        
        int mid = (n-1)/2;
        ListNode* pmid = head;
        for (int i = 0; i < mid; i++) {
            pmid = pmid -> next;
        }
        ret = new TreeNode(pmid -> val);
        ret -> left = sortedListToBSTCore(head, mid);
        ret -> right = sortedListToBSTCore(pmid -> next, n - mid - 1);
        return ret;
        
    }
};

