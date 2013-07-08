/*
 * =====================================================================================
 *
 *       Filename:  AddTwoNumbers.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/2 22:34:33
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int c = 0;
        while ((p1 -> next != NULL) && (p2 -> next != NULL)) {
            int n1 = p1 -> val;
            int n2 = p2 -> val;
            int sum = n1 + n2 + c;
            c = sum / 10;
            p1 -> val = sum % 10;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        int n1 = p1 -> val;
        int n2 = p2 -> val;
        int sum = n1 + n2 + c;
        c = sum / 10;
        p1 -> val = sum % 10;
        if (p1 -> next == p2 -> next) {
            if (c != 0) {
                l2 -> val = c;
                l2 -> next = NULL;
                p1 -> next = l2;
            }        
            return l1; 
        }
        if (p1 -> next == NULL) {
            p1 -> next = p2 -> next;
        }
        while ((c != 0) && (p1 -> next != NULL)) {
            int n1 = p1 -> next -> val;
            int sum = n1 + c;
            c = sum / 10;
            p1 -> next -> val = sum % 10;
            p1 = p1 -> next;
        }
        if (c != 0) {
            l2 -> val = c;
            l2 -> next = NULL;
            p1 -> next = l2;
        }        
        return l1;
    }
};

