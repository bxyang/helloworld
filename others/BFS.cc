/*
 * =====================================================================================
 *
 *       Filename:  BFS.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/08/2013 09:18:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<vector>
#include<queue>
using namespace std;

enum VColor {WHITE = 0, GRAY, BLACK};

void bfs(vector<vector<int> > adj_list, int s) {
    int adj_size = adj_list.size();
    vector<VColor> vertex_color(adj_size, VColor(WHITE));
    vector<int> dst(adj_size, adj_size + 1);
    dst[s] = 0;
    vector<int> prt(adj_size, -1);
    prt[s] = -1;
    queue<int> q;
    q.push(s);
    while (!(q.empty())) {
        int v = q.front();
        for (vector<int>::iterator it = adj_list[v].begin();
            it != adj_list[v].end(); it++) {
            if (vertex_color[*it] == WHITE) {
                vertex_color[*it] = GRAY;
                dst[*it] = dst[v] + 1;
                prt[*it] = v;
                q.push(*it);
            }
        }
        vertex_color[v] = BLACK;
        q.pop();
    }
}

void dfs(vector<vector<int> > adj_list, int s) {

}

int main() {


    return 0;
}
