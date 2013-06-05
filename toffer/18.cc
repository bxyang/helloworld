/*
 * =====================================================================================
 *
 *       Filename:  18.cc
 *
 *    Description:  judge whether BinaryTree-B is a subtree of BinaryTree-A
 *
 *        Version:  1.0
 *        Created:  06/05/2013 10:40:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdlib>


struct BiTreeNode {
    int data;
    BiTreeNode* left;
    BiTreeNode* right;
};

bool if_a_have_b(BiTreeNode* ra, BiTreeNode* rb) {
    if (ra == rb)
        return true;
    if (ra == NULL)
        return false;
    if (rb == NULL)
        return true;
    if (ra -> data != rb -> data)
        return false;
    else
        return (if_a_have_b(ra -> left, rb -> left)) && (if_a_have_b(ra -> left, rb -> left));
}

bool is_subtree(BiTreeNode* ra, BiTreeNode* rb) {
    if ((ra == NULL) || (rb == NULL))
        return false;
    int r = rb -> data;
    if ((ra -> data == r) && if_a_have_b(ra, rb))
        return true;
    if(is_subtree(ra -> left, rb))
        return true;
    if(is_subtree(ra -> right, rb))
        return true;
    return false;
}

int main() {
    return 0;
}
