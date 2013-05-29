/*
 * =====================================================================================
 *
 *       Filename:  5.cc
 *
 *    Description:  print linklist reversely
 *
 *        Version:  1.0
 *        Created:  05/29/2013 03:16:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<stack>

template<class T>
struct ListNode {
    T data;
    ListNode<T>* next;    
};

template<class T>
void add2tail(ListNode<T>** p_head, T data) {
    assert (p_head != NULL);
    ListNode<T>* p_node = new ListNode<T>();
    p_node -> next = NULL;
    p_node -> data = data;
    if (*p_head == NULL)
        *p_head = p_node;
    else {
        while((*p_head) -> next != NULL) {
            p_head = &((*p_head) -> next);
        }
        (*p_head) -> next = p_node;
    }
}

template<class T>
void print(ListNode<T>* head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        printf("%.3f ", (double)head -> data);
        head = head -> next;
    }
    printf("\n");
}
template<class T>
void reverse(ListNode<T>** head) {
    if (*head == NULL)
        return;
    ListNode<T>* q_prev = NULL;
    ListNode<T>* q = *head;
    while (q != NULL) {
        ListNode<T>* t = q -> next;
        q -> next = q_prev;
        q_prev = q;
        q = t;
    }
    *head = q_prev;
}

template<class T>
void print_reverse_recusive(ListNode<T>* head) {
    if (head == NULL)
        return;
    print_reverse_recusive(head -> next);
    printf("%.3f ", (double)head -> data);
}

template<class T>
void print_reverse_by_stack(ListNode<T>* head) {
    if (head == NULL)
        return;
    std::stack<ListNode<T>*> temp;
    while (head != NULL) {
        temp.push(head);
        head = head -> next;
    }
    while (!temp.empty()) {
        printf("%.3f ", double((temp.top()) -> data));
        temp.pop();
    }
}
int main() {
    ListNode<int>* head = NULL;
    for (int i = 0; i < 5; i++) {
        add2tail(&head, i);
    }
    print(head);
    // print_reverse_recusive(head);
    // printf("\n");
    // print_reverse_by_stack(head);
    // printf("\n");
    reverse(&head);
    print(head);
    reverse(&head);
    print(head);
    return 0;
}
