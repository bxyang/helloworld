/*
 * =====================================================================================
 *
 *       Filename:  15.cc
 *
 *    Description:  return the last but k-1 linklist node
 *
 *        Version:  1.0
 *        Created:  06/04/2013 10:32:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cassert>

struct ListNode {
    int data;
    ListNode* next;
};

ListNode* get_reversely(ListNode* head, int k) {
    if ((head == NULL) | (k < 1) )
        return NULL;
    ListNode* p = head;
    ListNode* q = head;
    for (int i = 0; (i < k - 1) && (p != NULL); k--)
        p = p -> next;
    if (p == NULL)
        return NULL;
    while (p -> next != NULL) {
        p = p -> next;
        q = q -> next;
    }
    return q;
}

void print(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

int main() {
    ListNode* head = new ListNode();
    head -> next = NULL;
    head -> data = 0;
    ListNode* p = head;
    for (int i = 1; i < 10; i++) {
        ListNode* tmp = new ListNode();
        tmp -> next = p -> next;
        tmp -> data = i;
        p -> next = tmp;
        p = p -> next;
    }
    print(head);
    for (int i = 1; i <= 10; i++)
        assert((get_reversely(head, i)) -> data == (10 - i));
    assert(get_reversely(head, 11) == NULL);
    return 0;
}
