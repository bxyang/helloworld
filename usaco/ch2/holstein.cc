/*
ID: yangbao1
PROG: holstein
LANG: C++
*/


#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int v;
int min_req_amt[25];
int g;
int feed_type[15][1000];

void min_scoop(int next, int* cons, vector<int> &path) {
    if (next == g) return;
    bool flag = true;
    for (int i = 0; i < v; i++) {
        cons[i] -= feed_type[next][i];
        if (cons[i] > 0) flag = false;
    }
    
    if (flag) {
        path.push_back(next);
        for (int i = 0; i < v; i++) 
            cons[i] += feed_type[next][i];
        return;
    }
    
    min_scoop(next+1, cons, path);
    for (int i = 0; i < v; i++) 
        cons[i] += feed_type[next][i];
    
    if (path.size() == 0) return; 
    else path.push_back(next);
    
    vector<int> p1;
    min_scoop(next+1, cons, p1);
    if ((p1.size() > 0) && (p1.size() < path.size()))
        path = p1;
}


int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w+", stdout); 
    cin >> v;
    for (int i = 0; i < v; i++)
        cin >> min_req_amt[i];
    cin >> g;
    for (int i = 0; i < g; i++) {
        for (int j = 0; j < v; j++)
            cin >> feed_type[i][j];
    }

    vector<int> path;
    min_scoop(0, min_req_amt, path);
    cout << path.size();
    for (int i = path.size() - 1; i >= 0; i--)
        cout << " " << (path[i] + 1);
    cout << endl;
   
    return 0;
}
