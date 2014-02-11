/*
 * =====================================================================================
 *
 *       Filename:  MultiWayTree2BinaryTree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/16 13:18:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<vector>
#include<cstdlib>
#include<cstdio>
#include<queue>
using namespace std;

struct MWNode {
    int val;
    vector<MWNode* > childs;
    MWNode(int v): val(v){};
};

struct BTNode {
    int val;
    BTNode* fchild;
    BTNode* brother;
    BTNode(int v): val(v), fchild(NULL), brother(NULL){}
};

MWNode* BT2MWT(BTNode* root) {
    MWNode* new_node = new MWNode(root -> val);
    BTNode* p = root -> fchild;
    while (p != NULL) {
        new_node -> childs.push_back(BT2MWT(p));
        p = p -> brother;
    }
    return new_node;
}

int main () {
    BTNode* nodes[8];
    for (int i = 0; i < 8; i++)
        nodes[i] = new BTNode(i);
    nodes[0] -> fchild = nodes[1];
    nodes[1] -> fchild = nodes[2];
    nodes[1] -> brother = nodes[3];
    nodes[2] -> fchild = nodes[4];
    nodes[2] -> brother = nodes[5];
    nodes[3] -> fchild = nodes[6];
    nodes[3] -> brother = nodes[7];
    MWNode* root = BT2MWT(nodes[0]);
    
    queue<MWNode* > q;
    q.push(root);
    while (!q.empty()) {
        MWNode* qq = q.front();
        q.pop();
        for (int i = 0; i < qq -> childs.size(); i++) {
            printf("%d ", (qq -> childs)[i] -> val);
            q.push((qq -> childs)[i]);
        }
        printf("\n");
    }
    return 0;
}
