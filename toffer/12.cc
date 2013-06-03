/*
 * =====================================================================================
 *
 *       Filename:  12.cc
 *
 *    Description:  print from 1 to the max number of the n-digits 
 *
 *        Version:  1.0
 *        Created:  06/03/2013 02:28:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdio>
#include<string.h>

int str_plus_1(char* str, int n, int digit_num) {
    int i = 0;
    char* p = str + n - 1;
    while (i <= n) {
        i++;
        int digit = (int)(*p);
        if (digit < 57) {
            digit += 1;
            *(p--) = (char)digit;
            break;
        } else {
            *(p--) = '0';
        }
    }
    if (i == (n + 1))
        return -1;
    else
        return (digit_num > i) ? digit_num : i;
}

void print_n_digit(int n) {
    if (n < 1)
        return;
    char* str = new char[n+1];
    for (int i = 0; i < n; i++)
        str[i] = '0';
    str[n] = '\0';
    int digit_num = 1;
    while (digit_num != -1) {
        printf("%s\n", str + n - digit_num);
        digit_num = str_plus_1(str, n, digit_num);
    }
}

void print_n_digit_recursive (int n, char* p, int idx) {
    if (idx == n) {
        printf("%s\n", p);
        return;
    }
    int start = 48;
    if (idx == (n - 1)) // from 1 rather than 0
        start = 49;
    for (int i = start; i < 58; i++) {
        p[idx] = (char)i;
        print_n_digit_recursive(n, p, idx + 1);
    }
}

void print_n_digit2(int n) {
    if (n < 1)
        return;
    char* str = new char[n+1];
    for (int i = 0; i < (n - 1); i++)
        str[i] = '0';
    str[n-1] = '1';
    str[n] = '\0';
    print_n_digit_recursive(n, str, 0);
}

int main () {
    // print_n_digit(1);
    print_n_digit2(2);
}
