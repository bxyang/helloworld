/*
ID: yangbao1
PROG: hamming
LANG: C++
*/


#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;

int n, b, d;
bool dist[256][256];

bool find(int next, vector<int> &path) {
    if (path.size() == n) return true;
    if (next == b) return false;
    
    bool flag = true;
    for (vector<int>::iterator it = path.begin(); it != path.end(); it++) {
        if (dist[next][*it]) continue;
        flag = false;
        break;
    }
    path.push_back(next);
    if (flag && (find(next+1, path)) ) return true;
    path.pop_back();
    
    return find(next+1, path);
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w+", stdout);   
    cin >> n >> b >> d;
    b = (0x1 << b);
    for (int i = 0; i < 256; i++) {
        for (int j = i; j < 256; j++) {
            int h = 0;
            int t = i ^ j;
            h += (t & 0x1);
            h += ((t & 0x2) != 0);
            h += ((t & 0x4) != 0);
            h += ((t & 0x8) != 0);
            h += ((t & 0x10) != 0);
            h += ((t & 0x20) != 0);
            h += ((t & 0x40) != 0);
            h += ((t & 0x80) != 0);
            dist[i][j] = (h >= d);
            dist[j][i] = (h >= d);
        }
    }
    
    vector<int> path;
    find(0, path);
    int l = path.size();
    for (int i = 0; i < l; i++) {
        cout << path[i++];
        for (int j = 1; (j <= 9) && (i < l); j++, i++)
            cout << " " << path[i];
        i--;
        cout << endl;   
    }
    return 0;
}



