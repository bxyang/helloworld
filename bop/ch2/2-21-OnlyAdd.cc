/*
 * =====================================================================================
 *
 *       Filename:  2-21-OnlyAdd.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/11/2013 02:33:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cmath>
#include<cstdlib>
#include<cstdio>

void solve(unsigned int num) {
    // n * (i+ i+n-1) = 2*num
    // 2=< n < sqrt(2*num)
    
    unsigned int max_n = sqrt(2)*sqrt(num);
    for (unsigned int j = 2; j <= max_n; j +=2) {
        unsigned int t = j >> 1;
        if (num % t == 0) {
            int i = (int)(num / t + 1) - j;
            if ((i > 0)&&((i&0x1)==0)) {
                i = i>>1;
                if (i > 0)
                    printf("%d %d\n", i, j);
            }
        }
    }
    for (unsigned int j = 3; j <= max_n; j +=2) {
        if (num % j == 0) {
            int i = (num / j * 2 - j + 1);
            if ((i > 0)&&((i&0x01)==0)) {
                i = i>>1;
                if (i > 0)
                    printf("%d %d\n", i, j);
            }
        }
    }
}

int main() {
    solve(3);
    solve(9);
    return 0;
}
