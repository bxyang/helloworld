/*
 * =====================================================================================
 *
 *       Filename:  ReverseLinkedListII.cc
 *
 *    Description:  

        Reverse a linked list from position m to n. Do it in-place and in one-pass.

        For example:
        Given 1->2->3->4->5->NULL, m = 2 and n = 4,

        return 1->4->3->2->5->NULL.

        Note:
        Given m, n satisfy the following condition:
        1 <= m <= n <= length of list.

 *
 *        Version:  1.0
 *        Created:  2013/7/16 10:41:53
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((m < 1) || (n <= m)) 
            return head;
        ListNode* prev_pm;
        ListNode* p = head;
        if (m==1)
            prev_pm = NULL;
        else {
            for (int i = 0; (i < (m-2)) && (p != NULL); i++)
                p = p -> next;
            if ((p == NULL) || (p -> next == NULL))
                return head;
            prev_pm = p;
            p = p -> next;
        }
        ListNode* next_p = p -> next;
        int i = m;
        while ((next_p != NULL) && (i < n)) {
            ListNode* next_next_p = next_p -> next;
            next_p -> next = p;
            p = next_p;
            next_p = next_next_p;
            i++;
        }
        if (prev_pm == NULL) {
            head -> next = next_p;
            return p;
        }
        prev_pm -> next -> next = next_p;
        prev_pm -> next = p;
        return head;
    }
};

