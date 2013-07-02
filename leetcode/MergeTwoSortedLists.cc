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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p1_prev = NULL;
        ListNode *p2_prev = NULL;
        while ((p1 != NULL) && (p2 != NULL)) {
            if (p1 -> val <= p2 -> val) {
                p1_prev = p1;
                p1 = p1 -> next;
                continue;
            }               
            int key = p1 -> val;
            if (p1_prev == NULL){
                l1 = p2;
            } else {
                p1_prev -> next = p2;
            }
            while ((p2 != NULL) && (p2 -> val <= key)){
                p2_prev = p2;
                p2 = p2 -> next;                
            }
            p2_prev -> next = p1;
            p2_prev = NULL;
            p1_prev = p1;
            p1 = p1 -> next;            
        }
        if (p1 == p2)
            return l1;
        if (p2 == NULL)
            return l1;
        p1_prev -> next = p2;
        if (p2_prev != NULL) {
            p2_prev -> next = NULL;
        }
        return l1;
    }
};
