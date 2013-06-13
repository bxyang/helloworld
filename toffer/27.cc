/*
 * =====================================================================================
 *
 *       Filename:  27.cc
 *
 *    Description:  convert binary search tree to double linklist
 *
 *        Version:  1.0
 *        Created:  06/09/2013 03:48:30 PM
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

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

void print_linklist(BinaryTreeNode* tail);

BinaryTreeNode* binary_tree2link_list(BinaryTreeNode* root, BinaryTreeNode* parent) {
    if (root == NULL)
        return NULL;
    if (root -> left == NULL) {
        if ((parent == NULL) || (root == parent -> left))
            root -> left = NULL;
        else {
            root -> left = parent;
        }
    }
    else
        root -> left = binary_tree2link_list(root -> left, root);
    if (root -> right == NULL)
        return root;
    else
        return binary_tree2link_list(root -> right, root);
}

BinaryTreeNode* binary_tree2double_link_list(BinaryTreeNode* root) {
    if (root == NULL)
        return NULL;
    BinaryTreeNode* tail = binary_tree2link_list(root, NULL);
    print_linklist(tail);
    tail -> right = NULL;
    while (tail -> left != NULL) {
        tail -> left -> right = tail;
        tail = tail -> left;
    }
    return tail;
} 

void print_linklist(BinaryTreeNode* tail) {
    while(tail != NULL){
        printf("%d ", tail -> data);
        tail = tail -> left;
    }
    printf("\n");
}

void print_double_linklist(BinaryTreeNode* head) {
    while(head != NULL) {
        printf("self=%d ", head -> data);
        if (head -> left != NULL)
            printf("previous=%d ", head -> left -> data);
        if (head -> right != NULL)
            printf("next=%d ", head -> right -> data);
        printf("\n");
        head = head -> right;
    }
}
int main() {
    BinaryTreeNode root[5];
    root[0].data = 10;
    root[1].data = 5;
    root[2].data = 12;
    root[3].data = 4;
    root[4].data = 7;
    root[0].left = root + 1;
    root[0].right = root + 2;
    root[1].left = root + 3;
    root[1].right = root + 4;
    root[2].left = NULL;
    root[2].right = NULL;
    root[3].left = NULL;
    root[3].right = NULL;
    root[4].left = NULL;
    root[4].right = NULL;
    print_double_linklist(binary_tree2double_link_list(root));
}
