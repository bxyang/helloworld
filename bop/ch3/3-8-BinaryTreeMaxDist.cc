/*
 * =====================================================================================
 *
 *       Filename:  3-8-BinaryTreeMaxDist.cc
 *
 *    Description:  find the max distance of two nodes in binary tree
 *
 *        Version:  1.0
 *        Created:  07/19/2013 09:53:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<utility>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

struct BiTreeNode {
    int val;
    BiTreeNode *left;
    BiTreeNode *right;
    BiTreeNode(int v): val(v), left(NULL), right(NULL){}
};




pair<int, int> minDist(BiTreeNode* root) {
    if ((root -> left == NULL) && (root -> right == NULL))
        return pair<int, int>(0, 0);
    pair<int, int> ret_left(0, 0);
    if (root -> left != NULL)
        ret_left = minDist(root -> left);
    pair<int, int> ret_right(0, 0);
    if (root -> right != NULL)
        ret_right = minDist(root -> right);
    pair<int, int> ret(0, 0);
    ret.first = 1 + (ret_left.first > ret_right.first ? ret_left.first : ret_right.first);
    ret.second = ret_left.second > ret_right.second ? ret_left.second : ret_right.second;
    int tmp = ret_left.first + ret_right.first + 2;
    ret.second = ret.second > tmp ? ret.second : tmp;
    return ret;
}

BiTreeNode* construct_binary_tree(vector<string> bi_nodes) {
    if (bi_nodes.size() == 0)
        return NULL;
    vector<string>::iterator it = bi_nodes.begin();
    BiTreeNode* root = new BiTreeNode(atoi((*it).c_str()));
    it++;
    BiTreeNode* p = root;
    queue<BiTreeNode* > q;
    q.push(p);
    while ((! q.empty()) && (it != bi_nodes.end())) {
        p = q.front();
        q.pop();
        if (*it == string("#"))
            p -> left = NULL;
        else {
            p -> left = new BiTreeNode(atoi((*it).c_str()));
            q.push(p -> left);
        }
        it++;
        if (*it == string("#"))
            p -> right = NULL;
        else {
            p -> right = new BiTreeNode(atoi((*it).c_str()));
            q.push(p -> right);
        }
        it++;
    }
    return root;
}


int main() {
    vector<string> bi_nodes;
    int data[13] = {1, 2, 3, 4, 5, 6, 7, 8, -1, -1, -1, -1, 9};
    for (int i = 0; i < 13; i++) {
        if (data[i] == -1)
            bi_nodes.push_back("#");
        else
            bi_nodes.push_back(string("1"));
    }
    pair<int, int> t = minDist(construct_binary_tree(bi_nodes)); 
    printf("%d\n", t.second);
}
