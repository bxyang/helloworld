/*
 * =====================================================================================
 *
 *       Filename:  RotateList.cc
 *
 *    Description:  
        // shift right may be more precise.
        Given a list, rotate the list to the right by k places, where k is non-negative.

        For example:
        Given 1->2->3->4->5->NULL and k = 2,
        return 4->5->1->2->3->NULL.
 *
 *        Version:  1.0
 *        Created:  2013/7/26 15:39:02
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((k < 0) || (head == NULL))
            return head;
        int len = 0;
        ListNode* p1 = head;
        ListNode* tail;
        while (p1 != NULL){
            tail = p1;
            p1 = p1 -> next;
            len++;
        }
        k = k % len;
        if (k == 0)
            return head;
        k = len - k;
        int i = 1;
        p1 = head;
        while (i < k) {
            p1 = p1 -> next;
            i++;
        }
        ListNode* ret = p1 -> next;
        p1 -> next = NULL;
        tail -> next = head;
        return ret;
    }
};

