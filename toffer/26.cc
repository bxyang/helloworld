/*
 * =====================================================================================
 *
 *       Filename:  26.cc
 *
 *    Description:  copy complex linklist
 *
 *        Version:  1.0
 *        Created:  06/09/2013 02:29:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */
#include<cstdlib>
#include<cstdio>

struct ComplexListNode {
    int data;
    ComplexListNode* next;
    ComplexListNode* sibling;
};

void print_list(ComplexListNode* head);

void clone_node(ComplexListNode* head) {
    ComplexListNode* p = head;
    while (p != NULL) {
        ComplexListNode* tmp = new ComplexListNode();
        tmp -> data = p -> data;
        tmp -> next = p -> next;
        tmp -> sibling = NULL;
        p -> next = tmp;
        p = tmp -> next;
    }
}

void clone_sibling(ComplexListNode* head) {
    ComplexListNode* p = head;
    while (p != NULL) {
        if (p -> sibling != NULL) {
            p -> next -> sibling = p -> sibling -> next;
        }
        p = p -> next -> next;
    }
}

ComplexListNode* reconnect_list (ComplexListNode* head) {
    ComplexListNode* p = head;
    ComplexListNode* ret = head -> next;
    while (p -> next != NULL) {
        ComplexListNode* tmp = p -> next;
        p -> next = p -> next -> next;
        p = tmp;
    }
    return ret;
}

ComplexListNode* clone_complex_list(ComplexListNode* head) {
    if (head == NULL)
        return NULL;
    clone_node(head);
    // print_list(head);
    clone_sibling(head);
    // print_list(head);
    return reconnect_list(head);
}

void print_list(ComplexListNode* head) {
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

int main() {
    ComplexListNode* node[5];
    for (int i = 0; i < 5; i++) {
        node[i] = new ComplexListNode();
        node[i] -> data = i;
    }
    for (int i = 0; i < 4; i++) {
        node[i] -> next = node[i+1];
    }
    node[4] -> next = NULL;
    node[0] -> sibling = node[2];
    node[1] -> sibling = node[4];
    node[2] -> sibling = NULL;
    node[3] -> sibling = node[1];
    node[4] -> sibling = NULL;
    print_list(node[0]);   
    print_list(clone_complex_list(node[0]));   
    print_list(node[0]);   
    return 0;
}
