/*
 * =====================================================================================
 *
 *       Filename:  LinkListLoop.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/6 15:06:35
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

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* get_loop_entry(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while ((fast != NULL) && (fast -> next != NULL)) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (fast == slow)
            break;
    }
    if ((fast == NULL) || (fast -> next == NULL))
        return NULL;
    slow = head;
    while (fast != head) {
        fast = fast -> next;
        slow = slow -> next;
    }
    return slow;
}

bool judge_loop(ListNode* head) {
    if (head == NULL)
        return false;
    ListNode* p = head;
    ListNode* q = head -> next;
    p -> next = NULL;
    while (q != NULL) {
        printf("v :%d\n" , q -> val);
        if (q == head)
            return true;
        ListNode* qq = q -> next;
        q -> next = p;
        p = q;
        q = qq;
    }
    return false;
}


int main() {
    ListNode* head = new ListNode();
    head -> val = 1;
    ListNode ch[4];
    for (int i = 0; i < 4; i++)
        ch[i].val = i+2;
    head -> next = &ch[0];
    ch[0].next = &ch[1];
    ch[1].next = &ch[2];
    ch[2].next = &ch[3];
    //ch[3].next = &ch[0];
    ch[3].next = NULL;
    if (judge_loop(head)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
