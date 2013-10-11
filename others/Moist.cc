/*
 * =====================================================================================
 *
 *       Filename:  Moist.cc
 *
 *    Description:
 *
 *
 *        Version:  1.0
 *        Created:  2013/9/14 9:37:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<list>
#include<iterator>
using namespace std;

int get_mov_num(list<char* > names);
int main() {
    int n;
    FILE* fin = fopen("C-small-2-attempt0.in", "r");
    FILE* fout = fopen("C-small-2-attempt0.out", "w");
    fscanf(fin, "%d\n", &n);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        int m;
        fscanf(fin, "%d\n", &m);
        list<char* > names;
        for (int j = 0; j < m; j++) {
            char* str = new char[101];
            fgets(str, 101, fin);
            names.push_back(str);
        }
        int ret = get_mov_num(names);
        if (i != n)
            fprintf(fout, "Case #%d: %d\n", i, ret);
        else
            fprintf(fout, "Case #%d: %d", i, ret);
    }
    return 0;
}

int get_mov_num(list<char* > names) {
    int ret = 0;
    int m = names.size();
    if (m < 2)
        return ret;
    list<char*>::iterator it = names.begin();
    it++;
    int i = 1;
    for (; it != names.end(); i++) {
        list<char*>::iterator p = names.begin();
        for (; p != it; p++) {
            if (strcmp(*p, *it) > 0)
                break;
        }
        if (p != it) {
            names.insert(p, *it);
            names.erase(it++);
            ret++;
        } else {
            it++;
        }
    }
    return ret;
}





































