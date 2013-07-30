/*
 * =====================================================================================
 *
 *       Filename:  RemoveDuplicatesfromSortedListII.cc
 *
 *    Description:  
        Given a sorted linked list, delete all nodes that have duplicate numbers, 
        leaving only distinct numbers from the original list.

        For example,
        Given 1->2->3->3->4->4->5, return 1->2->5.
        Given 1->1->1->2->3, return 2->3.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/29 13:11:35
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
        ListNode* tail = new ListNode(0);
        ListNode* pre= head;
        ListNode* p = head -> next;
        head = tail;
        bool flag = true;
        while (p != NULL) {
            if (p -> val == pre -> val) {
                flag = false;
                p = p -> next;
            } else {
                if (flag) {
                    tail -> next = pre;
                    tail = pre;
                }
                flag = true;
                pre = p;
                p = p -> next;
            }
        }
        if (flag)
            tail -> next = pre;
        else
            tail -> next = NULL;
        tail = head;
        delete tail;
        head = head -> next;
        return head;
        
    }
};

