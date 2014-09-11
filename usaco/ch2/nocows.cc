/*
ID: yangbao1
PROG: nocows
LANG: C++
*/

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdint.h>
#include <string>
using namespace std;

int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w+", stdout);
    int n, k;
    cin >> n >> k;

    uint64_t data [201][101];
    uint64_t sum[201][101];
    for (int i = 1; i <= k; i++) {
        data[1][i] = 0;
        sum[1][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        data[i][1] = 0;
        sum[i][1] = 0;
    }
    sum[1][1] = 1;
    data[1][1] = 1;

    for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
            data[j][i] = 0;
            for (int l = 1; l < (j - 1); l++) {
                data[j][i] += ((data[l][i-1] * data[j-1-l][i-1]))% 9901;
                if (i>2) data[j][i] += (2*(sum[l][i-2] * data[j-1-l][i-1])) % 9901;
            }
            sum[j][i] = (sum[j][i-1] + data[j][i]) % 9901;
        }
    }

    cout << data[n][k] % 9901 << endl;
}
