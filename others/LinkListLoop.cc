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
