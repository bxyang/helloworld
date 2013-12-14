/*
ID: yangbao1
PROG: sort3
LANG: C++
*/


#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;



int nums[1001];
int n;
int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w+", stdout);   
    
    int cnt[4];
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    
    int interval_cnt[4][4];
    memset(interval_cnt, 0, sizeof(interval_cnt));
    for (int i = 0; i < cnt[1]; i++)
        interval_cnt[1][nums[i]]++;
    int e = cnt[1] + cnt[2];
    for (int i = cnt[1]; i < e; i++)
        interval_cnt[2][nums[i]]++;
    for (int i = e; i < n; i++)
        interval_cnt[3][nums[i]]++;

    int exchange_cnt = 0;
    if (interval_cnt[1][2] > interval_cnt[2][1]) {
        interval_cnt[1][2] -= interval_cnt[2][1];
        interval_cnt[1][1] += interval_cnt[2][1];
        exchange_cnt += interval_cnt[2][1];
        interval_cnt[2][1] = 0;
    } else {
        interval_cnt[2][1] -= interval_cnt[1][2];
        interval_cnt[1][1] += interval_cnt[1][2];
        exchange_cnt += interval_cnt[1][2];
        interval_cnt[1][2] = 0;
    }
    


    if (interval_cnt[1][3] > interval_cnt[3][1]) {
        interval_cnt[1][3] -= interval_cnt[3][1];
        interval_cnt[1][1] += interval_cnt[3][1];
        exchange_cnt += interval_cnt[3][1];
        interval_cnt[3][1] = 0;
    } else {
        interval_cnt[3][1] -= interval_cnt[1][3];
        interval_cnt[1][1] += interval_cnt[1][3];
        exchange_cnt += interval_cnt[1][3];
        interval_cnt[1][3] = 0;
    }

    if (interval_cnt[2][3] > interval_cnt[3][2]) {
        interval_cnt[2][3] -= interval_cnt[3][2];
        interval_cnt[2][2] += interval_cnt[3][2];
        exchange_cnt += interval_cnt[3][2];
        interval_cnt[3][2] = 0;
    } else {
        interval_cnt[3][2] -= interval_cnt[2][3];
        interval_cnt[2][2] += interval_cnt[2][3];
        exchange_cnt += interval_cnt[2][3];
        interval_cnt[2][3] = 0;
    }

    if (interval_cnt[1][1] != cnt[1])
        exchange_cnt = exchange_cnt + 2*(interval_cnt[1][2] + interval_cnt[1][3]);
    
    cout << exchange_cnt << endl;

    return 0;
}
