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

long digit_num_of_one(char* str_n) {
    assert((str_n != NULL));
    if(*str_n == '0')
        return 0;
    char* p = str_n + 1;
    long ret = 0;
    while((*p != '\0') && (*p == '0'))
        p++;
    if (*p != '\0')
        ret = digit_num_of_one(str_n + 1);
    long len = strlen(str_n);
    // 1 ~ (10^(len - 1) - 1)
    long num_post = pow(10, (len - 1)) * (len - 1)/10;
    long first_digit = long(*str_n) - 48;
    if (first_digit ==1)
        ret += (num_post + 1 + atoi(str_n+1));
    else
        ret += (num_post * first_digit + pow(10, len - 1));
    return ret;
}


int main() {
    printf("%d\n", digit_num_of_one("1"));
    printf("%d\n", digit_num_of_one("5"));
    printf("%d\n", digit_num_of_one("10"));
    printf("%d\n", digit_num_of_one("55"));
    printf("%d\n", digit_num_of_one("99"));
    printf("%d\n", digit_num_of_one("10000"));
    printf("%d\n", digit_num_of_one("21345"));
    printf("%d\n", digit_num_of_one("0"));
    long start;
    long end;
    long* out = new long[100];
    long i = 0;
    while (true) {
        scanf("%ld %ld", &start, &end);
        if (feof(stdin))
            break; 
        char* str = new char[10];
        long s_num;
        if (start <= 1)
            s_num = 0;
        else {
            sprintf(str, "%ld", start - 1);
            s_num = digit_num_of_one(str);
        }
        sprintf(str, "%ld", end);
        long e_num = digit_num_of_one(str);
        out[i++] = e_num - s_num;
    }
    for (long k = 0; k < i; k++)
        printf("%ld\n", out[k]);
    return 0;
}
