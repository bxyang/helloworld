/*
 * =====================================================================================
 *
 *       Filename:  gb.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/12 9:40:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com (), 
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<list>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;


void producePx(int x[2], int y[2], vector<int> &px, vector<int> &py) {
    int d = y[1] - y[0] + 1;
    for (int i = x[0]; i <= x[1]; i++) {
        for (int j = 0; j < d; j++)
            px.push_back(i);
    }
    d = x[1] - x[0] + 1;
    for (int i = y[0]; i <= y[1]; i++) {
        for (int j = 0; j < d; j++)
            py.push_back(i);
    }
}

int computeDist(int m, vector<int> &px) {
    int n = px.size();
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += (abs(m-px[i]));
    return ret;
}
int main() {
    int caseNum;
    FILE* fin = fopen("B.txt", "r");
    FILE* fout = fopen("B.out", "w");
    fscanf(fin, "%d", &caseNum);
    for (int idx = 1; idx <= caseNum; idx++) {
        int areaNum;
        fscanf(fin, "%d", &areaNum);
        vector<int> px;
        vector<int> py;
        for (int i = 0; i < areaNum; i++) {
            int x[2];
            int y[2];
            fscanf(fin, "%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
            producePx(x, y, px, py);
        }
        sort(px.begin(), px.end());
        sort(py.begin(), py.end());
        int rx = px[px.size()/2];
        int ry = py[py.size()/2];
        int ret = 0;
        ret = ret + computeDist(rx, px);
        ret = ret + computeDist(ry, py);
        fprintf(fout, "Case #%d: %d %d %d\n", idx, rx, ry, ret);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
