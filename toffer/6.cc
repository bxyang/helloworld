/*
 * =====================================================================================
 *
 *       Filename:  6.cc
 *
 *    Description:  reconstruct binary tree
 *
 *        Version:  1.0
 *        Created:  05/30/2013 02:29:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cassert>
#include<cstring>
#include<string>
#include<stdexcept>

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* right;
    BinaryTreeNode* left;
};


BinaryTreeNode* reconstruct_binary_tree(int* preorder, int* inorder, int n) {
    if ((preorder == NULL) || (inorder == NULL) || n < 1)
        return NULL;
    BinaryTreeNode* root = new BinaryTreeNode();
    root -> data = preorder[0];
    int i = 0;
    for (; i < n; i++) {
        if (inorder[i] == preorder[0])
            break;
    }
    if (i == n) {
        throw std::invalid_argument("invalid input!\n");
    }
    else {
        root -> left = reconstruct_binary_tree(preorder + 1, inorder, i);
        root -> right = reconstruct_binary_tree(preorder + i + 1, 
                    inorder + i + 1, n - i - 1);
    }
    return root;
}

void preorder_print(BinaryTreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root -> data);
    preorder_print(root -> left);
    preorder_print(root -> right);
}

void inorder_print(BinaryTreeNode* root) {
    if (root == NULL)
        return;
    inorder_print(root -> left);
    printf("%d ", root -> data);
    inorder_print(root -> right);
}

int main() {
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode* root = reconstruct_binary_tree(preorder, inorder, 8);
    preorder_print(root);
    printf("\n");
    inorder_print(root);
    printf("\n");
    return 0;
}
