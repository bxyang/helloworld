#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<list>
#include<iterator>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


bool cmp(int i, int j) {
    return i > j;
}
int main() {
    FILE* fin = fopen("C-large.in", "r");
    FILE* fout = fopen("C-large.out", "w");
    int case_num;
    fscanf(fin, "%d\n", &case_num);
    for (int i = 0; i < case_num; i++) {
        int n;
        fscanf(fin, "%d\n", &n);
        int* even = new int[n];
        int* even_idx = new int[n];
        int pe = 0;
        int* odd = new int[n];
        int* odd_idx = new int[n];
        int po = 0;
        for (int j = 0; j < n; j++) {
            int t;
            fscanf(fin, "%d", &t);
            if (t&0x1==1) {
                odd[po] = t;
                odd_idx[po] = j;
                po++;
            } else {
                even[pe] = t;
                even_idx[pe] = j;
                pe++;
            }
        }
        sort(even, even+pe, cmp);
        sort(odd, odd+po);
        int* data = new int[n];
        for (int j = 0; j < po; j++)
            data[odd_idx[j]] = odd[j];
        for (int j = 0; j < pe; j++)
            data[even_idx[j]] = even[j];
        fprintf(fout, "Case #%d:", i+1);
        for (int j = 0; j < n; j++)
            fprintf(fout, " %d", data[j]);
        fprintf(fout, "\n");
    }
}
