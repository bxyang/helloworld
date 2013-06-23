/*
 * =====================================================================================
 *
 *       Filename:  39.cc
 *
 *    Description:  the depth of binary tree
 *
 *        Version:  1.0
 *        Created:  06/18/2013 10:29:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


struct BiTreeNode {
    int data;
    BiTreeNode* left;
    BiTreeNode* right;

};

int get_depth_of_bi_tree (BiTreeNode* root) {
    if (root == NULL)
        return 0;
    int left_depth = get_depth_of_bi_tree(root -> left);
    int right_depth = get_depth_of_bi_tree(root -> right);
    int depth = (left_depth > right_depth) ? left_depth : right_depth;
    depth++;
    return depth;
}

bool is_balanced_bi_tree(BiTreeNode* root) {
    int ret = is_balanced_bi_tree_core(root);
    return (ret == -1) ? false : true;
}

int is_balanced_bi_tree_core(BiTreeNode* root) {
    if (root == NULL)
        return 0;
    int left_depth = get_depth_of_bi_tree(root -> left);
    if (left_depth == -1)
        return -1;
    int right_depth = get_depth_of_bi_tree(root -> right);
    if (right_depth == -1)
        return -1;
    int diff = left_depth - right_depth;
    if (diff < -1 || diff > 1)
        return -1;
    int depth = (left_depth > right_depth) ? left_depth : right_depth;
    depth++;
    return depth;
}


int main() {

    return 0;
}
