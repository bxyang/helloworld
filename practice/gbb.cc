#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<list>
#include<iterator>
#include<queue>
#include<iostream>
using namespace std;

#define ULL unsigned long long

bool dfs(int id, ULL* para, ULL idx, pair<ULL, ULL> cur, ULL* result) {
    if (id == 1) {
        if (idx == para[0]) {
            result[0] = cur.first;
            result[1] = cur.second;
            return true;
        } else if (idx > para[0])
            return false;
        return dfs(id, para, 2*idx, pair<ULL, ULL>(cur.first, cur.first+cur.second), result) || 
            dfs(id, para, 2*idx+1, pair<ULL, ULL>(cur.first+cur.second, cur.second), result);
    } else {
        if ((cur.first == para[0]) && (cur.second == para[1])) {
            result[0] = idx;
            return true;
        } else if (cur.first > para[0])
            return false;
        else if (cur.first == para[0]) {
            if (cur.second + cur.first > para[1])
                return false;
            return dfs(id, para, 2*idx, pair<ULL, ULL>(cur.first, cur.first+cur.second), result);
        }
        
        if (cur.second > para[1])
            return false;
        if (cur.second == para[1]) {
            if (cur.second + cur.first > para[0])
                return false;
            return dfs(id, para, 2*idx+1, pair<ULL, ULL>(cur.first+cur.second, cur.second), result);
        } 
        
        return dfs(id, para, 2*idx, pair<ULL, ULL>(cur.first, cur.first+cur.second), result) || 
            dfs(id, para, 2*idx+1, pair<ULL, ULL>(cur.first+cur.second, cur.second), result);
    }
} 

int main() {
    int n;
    FILE* fin = fopen("B-large.in", "r");
    FILE* fout = fopen("B-large.out", "w");
    fscanf(fin, "%d\n", &n);
    for (int i = 1; i <=n; i++) {
        int id;
        fscanf(fin, "%d", &id);
        ULL para[2];
        if (id == 1) {
            fscanf(fin, "%lld\n", &para[0]);
        } else
            fscanf(fin, "%lld %lld\n", &para[0], &para[1]);
        ULL result[2];
        dfs(id, para, 1, pair<ULL, ULL>(1, 1), result);
        if (id == 1)
            fprintf(fout, "Case #%d: %lld %lld\n", i, result[0], result[1]);
        else
            fprintf(fout, "Case #%d: %lld\n", i, result[0]);
        cout << i << endl;
    }
}
