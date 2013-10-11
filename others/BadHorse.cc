/*
 * =====================================================================================
 *
 *       Filename:  BadHorse.cc
 *
 *    Description:
        Problem

        As the leader of the Evil League of Evil, Bad Horse has a lot of problems to deal with. 
        Most recently, there have been far too many arguments and far too much backstabbing in the League, 
        so much so that Bad Horse has decided to split the league into two departments in order to separate troublesome members. 
        Being the Thoroughbred of Sin, Bad Horse isn't about to spend his valuable time figuring out 
        how to split the League members by himself. That what he's got you -- his loyal henchman -- for.

        Input

        The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a positive integer M on a line by itself -- the number of troublesome pairs of League members. The next M lines each contain a pair of names, separated by a single space.

        Output

        For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is either "Yes" or "No", depending on whether the League members mentioned in the input can be split into two groups with neither of the groups containing a troublesome pair.

        Limits

        1 ¡Ü T ¡Ü 100.
        Each member name will consist of only letters and the underscore character.
        Names are case-sensitive.
        No pair will appear more than once in the same test case.
        Each pair will contain two distinct League members.

        Small dataset

        1 ¡Ü M ¡Ü 10.

        Large dataset

        1 ¡Ü M ¡Ü 100.

        Sample


        Input 
            
        Output 
         
        2
        1
        Dead_Bowie Fake_Thomas_Jefferson
        3
        Dead_Bowie Fake_Thomas_Jefferson
        Fake_Thomas_Jefferson Fury_Leika
        Fury_Leika Dead_Bowie
        Case #1: Yes
        Case #2: No
 *
 *        Version:  1.0
 *        Created:  2013/9/14 11:36:48
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
#include<map>
#include<vector>
#include<queue>
using namespace std;


bool can_split(vector<vector<bool> > &matrix, int m);

int main() {
    FILE* fin = fopen("A-small-2-attempt0.in", "r");
    FILE* fout = fopen("A-small-2-attempt0.out", "w");
    int n;
    fscanf(fin, "%d\n", &n);
    for (int i = 1; i <= n; i++) {
        int m;
        fscanf(fin, "%d\n", &m);
        map<string, int> names;
        vector<vector<bool> > matrix(2*m, vector<bool>(2*m, false));
        int idx = 0;
        for (int j = 0; j < m; j++) {
            char p1[100];
            char p2[100];
            fscanf(fin, "%s %s\n", p1, p2);
            string s1(p1);
            string s2(p2); 
            int i1;
            int i2;
            if (names.find(s1) == names.end()) {
                i1 = (idx++);
                names.insert(pair<string, int>(s1, i1));
            } else {
                i1 = names[s1];
            }
            if (names.find(s2) == names.end()) {
                i2 = (idx++);
                names.insert(pair<string, int>(s2, i2));
            } else {
                i2 = names[s2];
            }
            matrix[i1][i2] = true;
            matrix[i2][i1] = true;
        }
        bool ret = can_split(matrix, idx);
        if (ret)
            fprintf(fout, "Case #%d: Yes\n", i);
        else
            fprintf(fout, "Case #%d: No\n", i);
    }
}

bool can_split(vector<vector<bool> > &matrix, int m) {
    vector<int> group(m, -1);
    queue<int> q;
    q.push(0);
    while (true) {
        if (q.empty()) {
            int i = 0;
            for (; i < m; i++) {
                if (group[i] == -1) {
                    q.push(i);
                    break;
                }
            }
            if (i == m)
                break;
        }
        int r = q.front();
        q.pop();
        if (group[r] == -1)
            group[r] = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[r][i]) {
                if (group[i] == group[r])
                    return false;
                if (group[i] == -1) {
                    group[i] = (group[r] == 0 ? 1 : 0);
                    q.push(i);
                }
            }
        }
    }
    return true;
}
