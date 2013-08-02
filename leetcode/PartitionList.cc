/*
 * =====================================================================================
 *
 *       Filename:  PartitionList.cc
 *
 *    Description:  
        Given a linked list and a value x, 
        partition it such that all nodes less than x come before nodes greater than or equal to x.

        You should preserve the original relative order of the nodes in each of the two partitions.

        For example,
        Given 1->4->3->2->5->2 and x = 3,
        return 1->2->2->4->3->5.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/2 10:36:02
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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = new ListNode(0);
        ListNode* tail1 = p1;
        ListNode* tail2 = p2;
        ListNode* p = head;
        while(p != NULL) {
            if (p -> val < x) {
                tail1 -> next = p;
                tail1 = p;
                p = p -> next;
            } else {
                tail2 -> next = p;
                tail2 = p;
                p = p -> next;
            }
        }
        tail1 -> next = NULL;
        tail2 -> next = NULL;
        if (tail1 == p1) {
            head = p2 -> next;
        } else if(tail2 == p2) {
            head = p1 -> next;
        } else {
            tail1 -> next = p2 -> next;
            head = p1 -> next;
        }
        delete p1;
        delete p2;
        return head;
    }
};

