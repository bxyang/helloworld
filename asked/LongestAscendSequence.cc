/*
 * =====================================================================================
 *
 *       Filename:  LongestAscendSequence.cc
 *
 *    Description:
 *      http://acm.nyist.net/JudgeOnline/problem.php?pid=17
 *
 *        Version:  1.0
 *        Created:  2013/9/25 16:55:23
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

int bi_search_ge(char* seq, int n, char target) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right - left)/2;
        if (seq[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int longest_ascend_seq(char* data) {
    int n = strlen(data);
    char* seq_tail_min = new char[n+1];
    const char* p = data;
    
    char min_c = p[0];
    for (int i = 1; i < n; i++) {
        if (p[i] < min_c)
            min_c = p[i];
    }

    seq_tail_min[0] = min_c-1;
    seq_tail_min[1] = p[0];
    int max_len = 0;

    for (int i = 1; i <= n; i++) {
        int f = bi_search_ge(seq_tail_min, max_len+1, p[i-1]);
        if (seq_tail_min[f] == p[i-1]) {
            
        } else if (seq_tail_min[f] > p[i-1]) {
            seq_tail_min[f] = p[i-1];
        } else {
            max_len++;
            seq_tail_min[max_len] = p[i-1];
        } 
    }
    return max_len;
}


int main() {
     int n;
     scanf("%d\n", &n);
     bool flag = true;
     for (int i = 0; i < n; i++) {
        char data[10001];
        scanf("%s", data);
        int m = longest_ascend_seq(data);
        if (flag) {
            printf("%d", m);
            flag = false;
        } else
            printf("\n%d", m);
     }
     return 0;
}
