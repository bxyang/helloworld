/*
 * =====================================================================================
 *
 *       Filename:  BiSearchTree.cc
 *
 *    Description:  binary search tree
 *
 *        Version:  1.0
 *        Created:  06/07/2013 11:09:48 AM
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
#include<string.h>
#include<cassert>
#include<stdexcept>

struct BiTreeNode {
    int data;
    BiTreeNode* left;
    BiTreeNode* right;
    BiTreeNode* parent;
};


class BiSearchTree {
 public:
    BiSearchTree();
    BiSearchTree(const int* data, int n);
    const BiTreeNode* min();
    const BiTreeNode* max();
    void insert(int t);
    const BiTreeNode* successor(int k);
    const BiTreeNode* predecessor(int k);
    ~BiSearchTree(){}
 private:
    BiTreeNode* root;
};

BiSearchTree::BiSearchTree() {
    root = NULL;
}

BiSearchTree::BiSearchTree(const int* data, int n) {
    if ((data == NULL) || n < 1)
        throw std::runtime_error("invalid arg");
    root = NULL;
    /* initialize random seed: */
    srand (time(NULL));
    int* p = new int[n];
    memcpy(p, data, sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        /* generate secret number between 0 and n - i: */
        int r = rand() % (n-i);
        insert(p[r]);
        p[r] = p[n-i-1];
    }
}

const BiTreeNode* BiSearchTree::min() {
    if (root == NULL)
        return NULL;
    BiTreeNode* p = root;
    while (p -> left != NULL)
        p = p -> left;
    return p;
}

const BiTreeNode* BiSearchTree::max() {
    if (root == NULL)
        return NULL;
    BiTreeNode* p = root;
    while (p -> right != NULL)
        p = p -> right;
    return p;
}

void BiSearchTree::insert(int t) {
    BiTreeNode* tmp = new BiTreeNode();
    tmp -> data = t;
    tmp -> left = NULL;
    tmp -> right = NULL;
    tmp -> parent = NULL;
    if (root == NULL) {
        root = tmp;
        return;
    }
    BiTreeNode* parent;
    BiTreeNode* child = root;
    while (child != NULL) {
        parent = child;
        if (t <= child -> data)
            child = child -> left;
        else
            child = child -> right;
    }
    tmp -> parent = parent;
    if (t <= parent -> data)
        parent -> left = tmp;
    else
        parent -> right = tmp;
}

const BiTreeNode* BiSearchTree::successor(int k) {
    if (root == NULL)
        return NULL;
    BiTreeNode* p = root;
    while (p != NULL) {
        if (p -> data == k)
            break;
        else if (p -> data > k)
            p = p -> left;
        else
            p = p -> right;
    }
    if (p == NULL)
        return NULL;
    if (p -> right != NULL) {
        BiTreeNode* tmp = root;
        root = p -> right;
        const BiTreeNode* ret = this -> min();
        root = tmp;
        return ret;
    }
    while ((p -> parent != NULL) && (p -> parent -> left != p))
        p = p -> parent;
    if (p == NULL)
        return NULL;
    return p -> parent;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    BiSearchTree obj(a, 5);
    assert((obj.successor(3)) -> data == 4);
    assert((obj.successor(4)) -> data == 5);
    assert((obj.successor(1)) -> data == 2);
    assert(obj.successor(5) == NULL);
    return 0;
}
