/*
 * =====================================================================================
 *
 *       Filename:  17.cc
 *
 *    Description:  merge sorted linklist
 *
 *        Version:  1.0
 *        Created:  06/04/2013 11:30:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cstdio>

struct ListNode {
    int data;
    ListNode* next;
};

ListNode* merge_linklist(ListNode* ha, ListNode* hb) {
    if (ha == NULL && hb == NULL)
        return NULL;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while ((ha != NULL && hb != NULL)) {
        int t;
        if (ha -> data > hb -> data) {
            t = hb -> data;
            hb = hb -> next;
        } else {
            t = ha -> data;
            ha = ha -> next;
        }
        if (head == NULL) {
            head = new ListNode();
            head -> next = NULL;
            head -> data = t;
            tail = head;
        } else {
            ListNode* tmp = new ListNode();
            tmp -> next = NULL;
            tmp -> data = t;
            tail -> next = tmp;
            tail = tmp;
        }
    }
    ListNode* p = ((ha == NULL) ? hb : ha);
    while (p != NULL) {
        int t = p -> data;
        if (head == NULL) {
            head = new ListNode();
            head -> next = NULL;
            head -> data = t;
            tail = head;
        } else {
            ListNode* tmp = new ListNode();
            tmp -> next = NULL;
            tmp -> data = t;
            tail -> next = tmp;
            tail = tmp;
        }
        p = p -> next;
    }
    return head;
}

void print(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

ListNode* construct_linklist(int* data, int n) {
    if ((data == NULL) || n < 1)
        return NULL;
    ListNode* head = new ListNode();
    head -> next = NULL;
    head -> data = data[0];
    ListNode* p = head;
    for (int i = 1; i < n; i++) {
        ListNode* tmp = new ListNode();
        tmp -> next = p -> next;
        tmp -> data = data[i];
        p -> next = tmp;
        p = p -> next;
    }
    return head;
}
int main() {
    int da[5] = {1, 3, 5, 8, 10};
    int db[6] = {1, 2, 6, 7, 10, 11};
    ListNode* ha = construct_linklist(da, 5);
    ListNode* hb = construct_linklist(db, 6);
    print(merge_linklist(ha, hb));
    return 0;
}
