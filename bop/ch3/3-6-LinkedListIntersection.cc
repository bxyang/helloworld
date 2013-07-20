/*
 * =====================================================================================
 *
 *       Filename:  3-6-LinkedListIntersection.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/18/2013 03:11:45 PM
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

struct Node {
    int val;
    Node* next;
    Node(int n):val(val), next(NULL){};
};


bool is_intersecting (Node* head1, Node* head2) {
    while (head1 -> next != NULL)
        head1 = head1 -> next;
    while (head2 -> next != NULL)
        head2 = head2 -> next;
    return head1 == head2;
}

bool is_existing_loop(Node* head) {
    if (head == NULL)
        return false;
    Node* slow = head;
    Node* fast = head -> next;
    while ((slow != fast) && (slow != NULL) && (fast != NULL)) {
        slow = slow -> next;
        fast = fast -> next;
        if (fast != NULL)
            fast = fast -> next;
    }
    
    return !((slow == NULL) || (fast == NULL));
}



int main() {
    Node* head1 = new Node(1);
    head1 -> next = new Node(2);
    head1 -> next -> next = head1;
    printf("%d\n", is_existing_loop(head1));
    head1 -> next -> next = NULL;
    printf("%d\n", is_existing_loop(head1));
    return 0;
}
