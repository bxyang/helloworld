/*
 * =====================================================================================
 *
 *       Filename:  25.cc
 *
 *    Description:  binary tree path equals given number
 *
 *        Version:  1.0
 *        Created:  06/08/2013 03:08:01 PM
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
#include<stack>
using namespace std;

struct BiTreeNode {
    int data;
    BiTreeNode* left;
    BiTreeNode* right;
};

void print_path(stack<BiTreeNode*> sa);
void find_path(BiTreeNode* p, int now, int sum) {
    static stack<BiTreeNode*> sa;
    static stack<int> sb;
    if (p == NULL) {
        if (now == sum)
            print_path(sa);
        return;
    }
    sa.push(p);
    if ((p -> left == NULL) && (p -> right == NULL))
        find_path(p -> left, now + (p -> data), sum);
    else {
        find_path(p -> left, now + (p -> data), sum);
        find_path(p -> right, now + (p -> data), sum);
    }
    sa.pop();
}

void print_path(stack<BiTreeNode*> sa) {
    stack<int> tmp;
    while(!sa.empty()) {
        tmp.push((sa.top()) -> data);
        sa.pop();
    }
    while(!tmp.empty()) {
        printf("%d ", tmp.top());
        tmp.pop();
    }
    printf("\n");
}

int main() {
    BiTreeNode root[5];
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
    find_path(root, 0, 19);
    return 0;
}
