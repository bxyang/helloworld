/*
 * =====================================================================================
 *
 *       Filename:  BSTAction.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/10 11:29:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com (), 
 *   Organization:  ict
 *
 * =====================================================================================
 */



#include<string>
using namespace std;

struct Node {
    int left;
    int right;
    int parent;
    Node():left(-1),right(-1),parent(-1){}
    Node(int l, int r, int p):left(l),right(r),parent(p){}
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Node* bst = new Node[n+1];
        for (int i = 1; i <= n; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            bst[i].left = l;
            bst[i].right = r;
            if (l != -1)
                bst[l].parent = i;
            if (r != -1)  
                bst[r].parent = i;
        }
        

    }
}
