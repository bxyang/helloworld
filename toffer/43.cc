/*
 * =====================================================================================
 *
 *       Filename:  43.cc
 *
 *    Description:  griddle possibility
 *
 *        Version:  1.0
 *        Created:  06/24/2013 08:06:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@ict.ac.cn
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdlib>
#include<cstdio>
#include<cassert>
#include<cmath>

typedef long long int_ll;

void calc_possibility_core(int* s, int next, int n, int_ll* counts);
int sum(int* s, int n);

void calc_possibility_recursive(int n) {
    int min = n;
    int max = 6*n;
    int c = 5*n+1;
    int_ll *counts = new int_ll[c];
    for (int i = 0; i < c; i++) {
        counts[i] = 0;
    }
    int* s = new int[n];
    calc_possibility_core(s, 0, n, counts);
    double all = pow(6, n);
    for (int i = 0; i < c; i++) {
        printf("sum=%d, possibility=%.3f\n", i+n, counts[i]/all);
    }
    delete []s;
    delete []counts;
}

void calc_possibility_core(int* s, int next, int n, int_ll* counts) {
    if (next == n) {
        int ret = sum(s, n);
        counts[ret - n]++;
        return;
    }
    for (int i = 1; i <= 6; i++) {
        s[next] = i;
        calc_possibility_core(s, next + 1, n, counts);
    }
}

int sum(int* s, int n) {
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += s[i];
    return ret;
}

int_ll sum(int_ll* s, int n) {
    int_ll ret = 0;
    for (int i = 0; i < n; i++)
        ret += s[i];
    return ret;
}


void calc_possibility(int n) {
    int min = n;
    int max = 6*n;
    int c = 5*n+1;
    int_ll *counts = new int_ll[c];
    for (int i = 0; i < c; i++)
        counts[i] = 0;
    int* s = new int[n];
    for (int i = 0; i < n; i++)
        s[i] = 0;
    bool flag = true;
    int pos = 0;
    double all = pow(6, n);
    int_ll i = all;
    while (true) {
        if (pos == (n - 1)) {
            int ret = sum(s, n - 1);
            for (int k = 1; k <= 6 ; k++) {
                counts[ret+k-n] += 1;
            }
            pos--;
            while ((pos > -1) && (s[pos] == 6))
                pos--;
            if (pos < 0)
                break;
            s[pos] += 1;
            pos++;
            for (int j = pos; j < n; j++)
                s[j] = 0;
        } else {
            s[pos] += 1;
            pos ++;
        }
    }
    for (int i = 0; i < c; i++) {
        printf("sum=%d, possibility=%.3f\n", i+n, counts[i]/all);
    }
    delete []s;
    delete []counts;
}

void calc_possibility2(int n) {
    int_ll* p_counts[2];
    p_counts[0] = new int_ll[n*6+1]; 
    p_counts[1] = new int_ll[n*6+1]; 
    for (int i = 0; i < 6*n + 1; i++) {
        p_counts[0][i] = 0; 
        p_counts[1][i] = 0; 
    }
    int flag = 0;
    for (int i = 1; i <= 6; i++)
        p_counts[flag][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++){
            p_counts[1-flag][j] = 0;
        }
        for (int j = i; j <= i*6; j++) {
            p_counts[1-flag][j] = 0;
            for (int k = 1; (k <= 6 ) && (j-k >= 0); k++)
                p_counts[1-flag][j] += p_counts[flag][j-k];
        }
        flag = 1 - flag;
    }
    double all = pow(6, n);
    for (int i = n; i <= 6*n; i++) {
        printf("sum=%d, possibility=%.3f\n", i, p_counts[flag][i]/all);
    }
    delete [] p_counts[0];
    delete [] p_counts[1];
}



int main() {
    // calc_possibility_recursive(4);
    // calc_possibility(4);
    calc_possibility2(4);
    return 0;
}
