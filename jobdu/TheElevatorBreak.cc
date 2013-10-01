/*
 * =====================================================================================
 *
 *       Filename:  TheElevatorBreak.cc
 *
 *    Description:  http://acm.tju.edu.cn/toj/showp2992.html
 *
 *        Version:  1.0
 *        Created:  2013/10/1 20:21:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdio>

long long minDiscontentSum(int* ci, int* ui, int* di, int n) {
    if (n < 2)
        return 0;
    long long* up_disc = new long long[n];
    long long* down_disc = new long long[n];
    long long sum = 0;
    up_disc[0] = 0;
    for (int i = 1; i < n; i++) {
        sum += ci[i-1]*ui[i-1];
        up_disc[i] = up_disc[i-1] + sum ;
    }
    down_disc[n-1] = 0;
    sum = 0;
    for (int i = n - 2; i >= 0; i--) {
        sum += ci[i+1]*di[i+1];
        down_disc[i] = down_disc[i+1] + sum;
    }
    
    long long ret = 0x7FFFFFFFFFFFFFFF;
    for (int i = 0; i < n; i++) {
        long long t = up_disc[i] + down_disc[i];
        ret = (ret < t ? ret : t);
    }
    delete []up_disc;
    delete []down_disc;
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int* ci = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", ci+i);
    int* ui = new int[n];
    int* di = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", ui+i, di+i);
    long long int m = minDiscontentSum(ci, ui, di, n);
    printf("%lld\n", m);
    delete []ci;
    delete []ui;
    delete []di;
}
