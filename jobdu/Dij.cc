/*
 * =====================================================================================
 *
 *       Filename:  Dij.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/9 15:56:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<vector>
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int getMinDistVertex(vector<int> &minDist, vector<bool> &flags);

int main() {
    int n, m, k;
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        vector<vector<int> > mat(n+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            int s, d, dist;
            scanf("%d %d %d", &s, &d, &dist);
            mat[s][d] = dist;
            mat[d][s] = dist;
        }

        vector<int> minDist(n+1, 0x7FFFFFFF);
        vector<bool> flags(n+1, false);
        minDist[n] = 0;
        int v;
        while ((v = getMinDistVertex(minDist, flags))) {
            int lastDist = minDist[v];
            flags[v] = true;
            for (int i = 1; i <= n; i++) {
                if (mat[v][i] == 0)
                    continue;
                int tmp = lastDist + mat[v][i];
                if (tmp < minDist[i])
                    minDist[i] = tmp;
            }
        }

        vector<int> minHop(n+1, 0x7FFFFFFF);
        vector<bool> flagsHop(n+1, false);
        minHop[1] = 0;
        
        while ((v = getMinDistVertex(minHop, flagsHop))) {
            int lastHop = minHop[v];
            /* 
            if (lastHop >= k)
                break;
            */
            flagsHop[v] = true;
            for (int i = 1; i <= n; i++) {
                if (mat[v][i] == 0)
                    continue;
                int tmp = lastHop + 1;
                if (tmp < minHop[i])
                    minHop[i] = tmp;
            }
        }

        vector<int> minDist2(n+1, 0x7FFFFFFF);
        vector<bool> flags2(n+1, false);
        minDist2[1] = 0;
        while ((v = getMinDistVertex(minDist2, flags2))) {
            int lastDist = minDist2[v];
            flags2[v] = true;
            for (int i = 1; i <= n; i++) {
                if (mat[v][i] == 0)
                    continue;
                int tmp = lastDist + mat[v][i];
                if (tmp < minDist2[i])
                    minDist2[i] = tmp;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            long long int sum = (long long)minDist[i] + minDist2[i];
            if ((sum == minDist[1]) && (minHop[i] <= k))
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

int getMinDistVertex(vector<int> &minDist, vector<bool> &flags) {
    int ret = 0;
    for (int i = 1; i < minDist.size(); i++) {
        if (flags[i])
            continue;
        ret = (minDist[ret] < minDist[i] ? ret : i);
    }
    return ret;
}
