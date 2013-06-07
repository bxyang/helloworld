/*
 * =====================================================================================
 *
 *       Filename:  23.cc
 *
 *    Description:  tranversing binary tree level by level
 *
 *        Version:  1.0
 *        Created:  06/07/2013 10:38:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<queue>
#include<cstdlib>
#include<cstdio>


struct BiTreeNode {
    int data;
    BiTreeNode* left;
    BiTreeNode* right;
};

void tranverse_binary_tree_level (BiTreeNode* root){
    if (root == NULL)
        return;
    std::queue<BiTreeNode*> tmp;
    tmp.push(root);
    while (!tmp.empty()) {
        BiTreeNode* pa = tmp.front();
        tmp.pop();
        if (pa -> left != NULL) {
            tmp.push(pa -> left);
            printf("%d ", pa -> left -> data);
        }
        if (pa -> right != NULL) {
            tmp.push(pa -> right);
            printf("%d ", pa -> right -> data);
        }
    }
}

int main() {
    return 0;
}
