/*
 * =====================================================================================
 *
 *       Filename:  TreeMinHeight.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/1 11:29:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstdio>

using namespace std;


int longest_path(vector<vector<int> > &mat, int n, int next, int& path);
int minHeight(vector<vector<int> > &mat, int n) {
    int path = 0;
    longest_path(mat, n, 0, path);
    return (path+1)/2;
}

int longest_path(vector<vector<int> > &mat, int n, int next, int& path) {
    mat[next][0] = 1;
    int ret = 0;
    
    int m[2] = {0, 0};
    int child_size = mat[next].size();
    for (int i = 1; i < child_size; i++) {
        if (mat[mat[next][i]][0])
            continue;
        int t = longest_path(mat, n, mat[next][i], path) + 1;
        if (t < m[1])
            continue;
        else if (t < m[0])
            m[1] = t;
        else {
            m[1] = m[0];
            m[0] = t;
        }
        ret = max(ret, t);
    }
    path = max(m[0]+m[1], path);
    return ret;
}


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<vector<int> > mat(n, vector<int>(1, 0));
        int i, j;
        for (int k = 1; k < n; k++) {
            scanf("%d %d", &i, &j);
            mat[i].push_back(j);
            mat[j].push_back(i);
        }
        int mh = minHeight(mat, n);
        printf("%d\n", mh);
    }
    return 0;
}
