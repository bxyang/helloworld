/*
ID: yangbao1
PROG: ariprog
LANG: C++
*/

#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define M 250
bool is_bisqure[2*M*M+1];

bool is_match(int a, int b, int n, int msq) {
    for (int i = 0; i < n; ++i) {
        if (a > msq) return false;
        if (!is_bisqure[a]) return false;
        a += b;
    }
    return true;
}

int main() {
    FILE *fin = fopen("ariprog.in", "r");
    FILE *fout = fopen("ariprog.out", "w+");   
    int n, m;
    fscanf(fin, "%d", &n);    
    fscanf(fin, "%d", &m);    
    memset(is_bisqure, 0, M*M);
    int sq[M+1];
    for (int i = 0; i <= m; i++)
        sq[i] = i*i;
    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++)
            is_bisqure[sq[i]+sq[j]] = 1;
    }
    m = 2*m * m;
    
    bool flag = true;
    int eb = m/(n-1);
    for (int b = 1; b <= eb; b++) {
        int ea = m-(n-1)*b;
        for (int a = 0; a <= ea; a++) {
            if (is_match(a, b, n, m)) {
                flag = false;
                fprintf(fout, "%d %d\n", a, b);
            }
        }
    }
    if (flag) fprintf(fout, "NONE\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
