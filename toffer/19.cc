/*
 * =====================================================================================
 *
 *       Filename:  19.cc
 *
 *    Description:  get the mirror image of a given binary tree
 *
 *        Version:  1.0
 *        Created:  06/05/2013 02:10:37 PM
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

void mirror_bi_tree(BiTreeNode* root) {
    if (root == NULL)
        return;
    if ((root -> left == NULL) && (root -> right == NULL))
        return;
    BiTreeNode* tmp = root -> left;
    root -> left = root -> right;
    root -> right = tmp;
    mirror_bi_tree(root -> left);
    mirror_bi_tree(root -> right);
}

int main() {
    return 0;
}
