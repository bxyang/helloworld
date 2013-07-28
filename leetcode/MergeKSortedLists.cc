/*
 * =====================================================================================
 *
 *       Filename:  MergeKSortedLists.cc
 *
 *    Description:  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
 *
 *        Version:  1.0
 *        Created:  2013/7/28 11:41:36
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.size() == 0)
            return NULL;
        return mergeKLists(lists, 0, lists.size() - 1);
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end) {
        if (start == end)
            return lists[start];
        if (start == (end - 1))
            return mergeTwoLists(lists[start], lists[end]);
        int mid = start + (end-start)/2;
        return mergeTwoLists(mergeKLists(lists, start, mid), 
                              mergeKLists(lists, mid+1, end));
    }
    
    ListNode *mergeTwoLists(ListNode* h1, ListNode* h2) {
        if (h1 == NULL)
            return h2;
        if (h2 == NULL)
            return h1;
        ListNode* p1 = h1;
        ListNode* tmp = new ListNode(0);
        ListNode* p1_prev = tmp;
        ListNode* p2 = h2;
        ListNode* p2_prev = tmp;
        while ((p1 != NULL) && (p2 != NULL)) {
            if (p1 -> val <= p2 -> val) {
                p2_prev -> next = p1;
                p2_prev = tmp;
                p1_prev = p1;
                p1 = p1 -> next;
            } else {
                p1_prev -> next = p2;
                p1_prev = tmp;
                p2_prev = p2;
                p2 = p2 -> next;
            }
        }
        if (p1 == NULL)
            p1_prev -> next = p2;
        else
            p2_prev -> next = p1;
        tmp -> next = NULL;
        delete tmp;
        if (h1 -> val <= h2 -> val)
            return h1;
        else
            return h2;
    }
};

