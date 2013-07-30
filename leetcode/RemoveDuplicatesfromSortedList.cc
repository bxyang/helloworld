/*
 * =====================================================================================
 *
 *       Filename:  RemoveDuplicatesfromSortedList.cc
 *
 *    Description:  
        Given a sorted linked list, delete all duplicates such that each element appear only once.

        For example,
        Given 1->1->2, return 1->2.
        Given 1->1->2->3->3, return 1->2->3.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/29 11:53:49
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
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((head == NULL) || (head -> next == NULL))
            return head;
        ListNode* pre = head;
        ListNode* p = head -> next;
        while (p != NULL) {
            if (p -> val == pre -> val) {
                p = p -> next;
                pre -> next = p;
            } else {
                pre = p;
                p = p -> next;
            }
        }
        return head;
    }
};

