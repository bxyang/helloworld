/*
 * =====================================================================================
 *
 *       Filename:  32.cc
 *
 *    Description:  the number of 1 for 1 to n
 *
 *        Version:  1.0
 *        Created:  06/14/2013 02:05:27 PM
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
#include<string.h>
#include<math.h>

long long digit_num_of_one(char* str_n) {
    assert((str_n != NULL));
    if(*str_n == '0')
        return 0;
    char* p = str_n + 1;
    long long ret = 0;
    while((*p != '\0') && (*p == '0'))
        p++;
    if (*p != '\0')
        ret = digit_num_of_one(str_n + 1);
    long long len = strlen(str_n);
    // 1 ~ (10^(len - 1) - 1)
    long long num_post = 1LL*pow(10,int(len - 1)) * (len - 1)/10;
    long long first_digit = int(*str_n) - 48;
    if (first_digit ==1)
        ret += (num_post + 1 + atoi(str_n+1));
    else
        ret += (num_post * first_digit + pow(10, len - 1));
    return ret;
}


int main() {
    long long start;
    long long end;
    long long i = 0;
    while (true) {
        scanf("%lld %lld", &start, &end);
        if (feof(stdin))
            break; 
        char* str = new char[10];
        long long s_num;
        if (start <= 1)
            s_num = 0;
        else {
            sprintf(str, "%lld", start - 1);
            s_num = digit_num_of_one(str);
        }
        sprintf(str, "%lld", end);
        long long e_num = digit_num_of_one(str);
        printf("%lld\n", e_num - s_num);
    }
    return 0;
}
