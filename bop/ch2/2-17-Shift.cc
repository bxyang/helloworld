/*
 * =====================================================================================
 *
 *       Filename:  2-17-Shift.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/07/2013 04:52:34 PM
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
#include<cassert>
#include<utility>

void reverse(int* data, int start, int end) {
    if ((data == NULL) || (start >= end))
        return;
    for (int i = start, j = end; i < j; i++, j--)
        std::swap(data[i], data[j]);
}

void right_shift(int* data, int n, unsigned int k) {
    assert((data != NULL) && (n>0));
    if (n==1)
        return;
    k = k % n;
    if (k == 0)
        return;
    reverse(data, 0, n-k-1);
    reverse(data, n-k, n-1);
    reverse(data, 0, n-1);
}

void print(int* data, int n) {
    for(int i = 0; i < n; i++, data++)
        printf("%d ", *data);
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    int* data = new int[n];
    for (int i = 0, *p = data; i < n; i++, p++)
        scanf("%d ", p);
    int k;
    scanf("%d", &k);
    right_shift(data, n, k);
    print(data, n);
    return 0;
}
