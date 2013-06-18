/*
 * =====================================================================================
 *
 *       Filename:  37.cc
 *
 *    Description:  find first shared node in two linklist
 *
 *        Version:  1.0
 *        Created:  06/18/2013 08:41:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cstdlib>

struct LinkListNode {
    int data;
    LinkListNode* next;
};

int get_linklist_length(LinkListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head -> next;
    }
    return length;
}
LinkListNode* find_first_common_node(LinkListNode* head1, LinkListNode* head2) {
    if ((head1 == NULL) || (head2 == NULL))
        return NULL;
    int len1 = get_linklist_length(head1);
    int len2 = get_linklist_length(head2);
    LinkListNode* p_short = NULL;
    LinkListNode* p_long = NULL;
    int dist;
    if (len1 < len2) {
        p_short = head1;
        p_long = head2;
        dist = len2 - len1;
    } else {
        p_short = head2;
        p_long = head1;
        dist = len1 - len2;
    }
    for (; dist >= 0; dist--)
        p_long = p_long -> next;
    while (p_long != NULL) {
        if (p_long == p_short)
            return p_long;
        p_short = p_short -> next;
        p_long = p_long -> next;
    }
    return NULL;
}


int main() {
    return 0;
}
