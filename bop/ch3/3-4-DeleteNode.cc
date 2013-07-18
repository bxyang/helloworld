/*
 * =====================================================================================
 *
 *       Filename:  3-4-DeleteNode.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/18/2013 09:50:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

struct Node {
    int val;
    Node* next;
}

bool del_node(struct Node* p) {
    if (p == NULL)
        return true;
    if (p -> next == NULL)
        return false;
    int val = p -> next -> val;
    p -> next = p -> next -> next;
    p -> next -> val = val;
}

int main (){
    return 0;
} 
