/*
 * =====================================================================================
 *
 *       Filename:  13.cc
 *
 *    Description:  delete linklist node with o(1) time
 *
 *        Version:  1.0
 *        Created:  06/03/2013 03:51:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cstdlib>

struct ListNode {
    int data;
    ListNode* next;
};

ListNode* del_node(ListNode* head, ListNode* node) {
    if ((head == NULL || node == NULL))
        return head;
    if (node -> next == NULL) {
        if (node == head) {
            delete node;
            return NULL;
        }
        else {
            ListNode* p = head;
            while (p -> next != node) {
                p = p -> next;
            }
            delete node;
            p -> next = NULL;
            return head;
        }
    } else {
        ListNode* p_next = node -> next;
        node -> next = p_next -> next;
        node -> data = p_next -> data;
        delete p_next;
        return head;
    }
}


int main() {

    return 0;
}
