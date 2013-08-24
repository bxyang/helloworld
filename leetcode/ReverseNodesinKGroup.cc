/*
 * =====================================================================================
 *
 *       Filename:  ReverseNodesinKGroup.cc
 *
 *    Description: 
        Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

        If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

        You may not alter the values in the nodes, only nodes itself may be changed.

        Only constant memory is allowed.

        For example,
        Given this linked list: 1->2->3->4->5

        For k = 2, you should return: 2->1->4->3->5
        For k = 3, you should return: 3->2->1->4->5
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/21 21:48:24
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((head == NULL) || (k < 2))
            return head;
        ListNode* p = head;
        int i = 0;
        while ( (p != NULL) && (i < k)) {
            p = p -> next;
            i++;
        }
        if (i < k)
            return head;
        i = 1;
        ListNode* q = head;
        ListNode* q_next = q -> next;
        while (i < k) {
            ListNode* tmp = q_next -> next;
            q_next -> next = q;
            q = q_next;
            q_next = tmp;
            i++;
        }
        head -> next = reverseKGroup(p, k);
        return q;
    }
};
