#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<list>
#include<iterator>
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<char* > &room_color, int* a, int* b, int* tim, 
        int m, vector<int> &path, int cur_p, int dst, int &min_tim, int cost_time) {
    if (cur_p == dst) {
        min_tim = (min_tim < cost_time ? min_tim : cost_time);
        return;
    }
    char* ncolor = room_color[cur_p];
    for (int i = cur_p+1; i < room_color.size(); i++) {
        if (strcmp(room_color[i], ncolor) == 0) {
            int p = 0;
            for (; p < path.size(); p++) {
                if (path[p] == i)
                    break;
            }
            if (p == path.size()) {
                path.push_back(cur_p);
                dfs(room_color, a, b, tim, m, path, i, dst, min_tim, cost_time);
                path.pop_back();
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (a[i] == cur_p) {
            int p = 0;
            for (; p < path.size(); p++) {
                if (path[p] == b[i])
                    break;
            }
            if (p == path.size()) {
                path.push_back(cur_p);
                dfs(room_color, a, b, tim, m, path, b[i], dst, min_tim, cost_time+tim[i]);
                path.pop_back();
            }
        }
    }
}


int main() {
    FILE* fin = fopen("t.in", "r");
    FILE* fout = fopen("t.out", "w");
    int t;
    fscanf(fin, "%d\n", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        fscanf(fin, "%d\n", &n);
        vector<char*> room_color(n, (char*)NULL);
        for (int j = 0; j < n; i++) {
            char* co = new char[3];
            fscanf(fin, "%s\n", co);
            room_color[j] = co;
        }
        int m;
        fscanf(fin, "%d\n", &m);
        int* a = new int[m];
        int* b = new int[m];
        int* tim = new int[m];
        for (int j = 0; j < m ; i++)
            fscanf(fin, "%d %d %d\n", &a[j], &b[j], &tim[j]);
        
        int soldier_num;
        fscanf(fin, "%d\n", &soldier_num);
        fprintf(fout, "Case #%d:\n", i);
        for (int s = 1; s <= soldier_num; s++) {
            int min_tim = 0x7fffffff;
            int p1;
            int p2;
            fscanf(fin, "%d %d\n", &p1, &p2);
            vector<int> path;
            dfs(room_color, a, b, tim, m, path, p1, p2, min_tim, 0);
            if (min_tim == 0x7fffffff)
                fprintf(fout, "%d\n", -1);
            else
                fprintf(fout, "%d\n", min_tim);
        }
    }
}
