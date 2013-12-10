/*
ID: yangbao1
PROG: milk3
LANG: C++
*/

#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define M 20

bool c_amt[M+1];
bool states[0x8000];

void pour(unsigned int& src, unsigned int& dst, const int dst_rem) {
    int p = (dst_rem >= src ? src : dst_rem);
    src -= p;
    dst += p;
}

inline unsigned int comb(unsigned int va, unsigned int vb, unsigned int vc) {
    return ( (va << 10) | (vb << 5) | vc);
}
void milk(unsigned int v, const int* capacity);

int main() {
    FILE *fin = fopen("milk3.in", "r");
    FILE *fout = fopen("milk3.out", "w+");   
    int capacity[3];
    fscanf(fin, "%d %d %d", &capacity[0], &capacity[1], &capacity[2]);
    fclose(fin);

    memset(c_amt, 0, sizeof(c_amt));
    memset(states, 0, sizeof(states));
    milk(capacity[2], capacity);

    int i = 0;
    for (; i <= M; ++i)
        if (c_amt[i]) {fprintf(fout, "%d", i); break;}
    for (++i; i <= M; ++i)
        if (c_amt[i]) fprintf(fout, " %d", i);
    fprintf(fout, "\n");
    fclose(fout);
    return 0;
}

void milk(unsigned int v, const int* capacity) {
    if (states[v]) return;
    states[v] = true;
    unsigned int va = (v & 0x7C00) >> 10;
    unsigned int vb = (v & 0x3E0) >> 5;
    unsigned int vc = (v & 0x1F);
    
    //cout << va << " " << vb << " " << vc << endl;

    int ra = capacity[0] - va;
    int rb = capacity[1] - vb;
    int rc = capacity[2] - vc;
    unsigned int nv = 0;
    if (va == 0) c_amt[vc] = 1;
    unsigned int src;
    unsigned int dst;
    if (va != 0) {
        src = va;
        dst = vb;
        pour(src, dst, rb);
        nv = comb(src, dst, vc);
        milk(nv, capacity);

        src = va;
        dst = vc;
        pour(src, dst, rc);
        nv = comb(src, vb, dst);
        milk(nv, capacity);
    }

    if (vb != 0) {
        src = vb;
        dst = va;
        pour(src, dst, ra);
        nv = comb(dst, src, vc);
        milk(nv, capacity);

        src = vb;
        dst = vc;
        pour(src, dst, rc);
        nv = comb(va, src, dst);
        milk(nv, capacity);
    }

    if (vc != 0) {
        src = vc;
        dst = va;
        pour(src, dst, ra);
        nv = comb(dst, vb, src);
        milk(nv, capacity);

        src = vc;
        dst = vb;
        pour(src, dst, rb);
        nv = comb(va, dst, src);
        milk(nv, capacity);
    }
}
