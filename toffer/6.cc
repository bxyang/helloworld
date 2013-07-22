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
#include<queue>
using namespace std;


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

BinaryTreeNode* reconstruct_binary_tree_iterative(int* preorder, int* inorder, int n) {
    if ((preorder == NULL) || (inorder == NULL) || n < 1)
        return NULL;
    BinaryTreeNode* root = new BinaryTreeNode();
    queue<BinaryTreeNode* > q_node;
    queue<int* > q_pre;
    queue<int* > q_in;
    queue<int> q_len;
    q_node.push(root);
    q_pre.push(preorder);
    q_in.push(inorder);
    q_len.push(n);
    while (! q_node.empty()) {
        BinaryTreeNode* node = q_node.front();
        int* pre = q_pre.front();
        int* in = q_in.front();
        int len = q_len.front();
        q_node.pop();
        q_pre.pop();
        q_in.pop();
        q_len.pop();
        if ((pre == NULL) || (in == NULL) || len < 1)
            continue;
        node -> data = pre[0];
        int i = 0;
        for (; i < len; i++) {
            if (in[i] == pre[0])
                break;
        }
        if (i == len) {
            throw std::invalid_argument("invalid input!\n");
        }
        else {
            node -> left = new BinaryTreeNode();
            node -> right = new BinaryTreeNode();
            q_node.push(node -> left);
            q_node.push(node -> right);
            q_pre.push(pre+1);
            q_pre.push(pre+i+1);
            q_in.push(in);
            q_in.push(in+i+1);
            q_len.push(i);
            q_len.push(len-i-1);
        }
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
    printf("reconstruct recursive\n");
    BinaryTreeNode* root = reconstruct_binary_tree(preorder, inorder, 8);
    preorder_print(root);
    printf("\n");
    inorder_print(root);
    printf("\n");

    printf("reconstruct interative\n");
    BinaryTreeNode* root_iterative = reconstruct_binary_tree_iterative(preorder, inorder, 8);
    preorder_print(root);
    printf("\n");
    inorder_print(root);
    printf("\n");
    return 0;
}
