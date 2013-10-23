/*
 * =====================================================================================
 *
 *       Filename:  isPrime.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/17 16:05:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */



void isPrime(int m) {
    vector<bool> flags(m+1, true);
    flag[0] = false;
    flag[1] = false;
    for (int i = 2; i <= m; i+=2)
        flag[i] = false;
    int t = sqrt(m*1.0);
    for (int i = 3; i <= t; i++) {
        if (!flags[i])
            continue;
        int step = i << 1;
        for (int j = i*i; j <= m; j += step)
            flag[j] = false;
    } 
}

int main() {

    return 0;
}
