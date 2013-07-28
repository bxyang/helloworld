/*
 * =====================================================================================
 *
 *       Filename:  SwapNodesInPairs.cc
 *
 *    Description:  
        Given a linked list, swap every two adjacent nodes and return its head.

        For example,
        Given 1->2->3->4, you should return the list as 2->1->4->3.

        Your algorithm should use only constant space. You may not modify the values in the list, 
        only nodes itself can be changed.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/27 12:47:29
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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* p1 = head;
        if (p1 == NULL)
            return head;
        ListNode* p2 = head -> next;
        if (p2 == NULL)
            return head;
        ListNode* ret = p2;
        ListNode* p3 = NULL;
        while (p2 != NULL) {
            p1 -> next = p2 -> next;
            p2 -> next = p1;
            p3 = p1;
            p1 = p1 -> next;
            if (p1 != NULL) {
                p2 = p1 -> next;
                if (p2 != NULL)
                    p3 -> next = p2;
                else {
                    p3 -> next = p1;
                    break;
                }
            }
            else
                break;
        }
        return ret;
    }
};
