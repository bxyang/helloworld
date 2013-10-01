/*
 * =====================================================================================
 *
 *       Filename:  BuyStocks.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/30 11:41:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;

int maxProfit(int* prices, int n, int k) {
    vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
    int ret = 0;  
    
    for (int trade_time = 1; trade_time <= k; trade_time++) { // trade times
        int  t = dp[1][trade_time-1] - prices[0];
        for (int day = 1; day <= n; day++) { // days
            // max dp[day-1][trade_time] max dp[i][trade_time-1] + prices[day-1] - prices[i-1], i from 1 to day-1 
            dp[day][trade_time] = t + prices[day-1];
            dp[day][trade_time] = max(dp[day][trade_time], dp[day-1][trade_time]);
            t = max(t, dp[day][trade_time-1] - prices[day-1]);
            ret = max(ret, dp[day][trade_time]);
        }
    }
    return ret;
}


int main() {
    int n;
    int k;
    while (scanf("%d %d", &n, &k) != EOF) {
        int* prices = new int[n];
        for (int i = 0; i < n; i++)
            scanf("%d", prices+i);
        int mp = maxProfit(prices, n, k);
        printf("%d\n", mp);
    }
    return 0;
}
