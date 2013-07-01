/*
 * =====================================================================================
 *
 *       Filename:  2-6-ShowFloat.cc
 *
 *    Description:  show float as fraction
 *
 *        Version:  1.0
 *        Created:  07/01/2013 02:25:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<string.h>
#include<cassert>
#include<utility>

int gcd(long long n1, long long n2) {
    if (n2 == 0)
        return n1;
    if (n1 < n2)
        std::swap(n1, n2);
    bool is_even[2] = {false, false};
    if (0x1 && n1 == 0)
        is_even[0] = true;
    if (0x1 && n2 == 0)
        is_even[1] = true;
    if (is_even[0] && is_even[1])
        return (gcd(n1 >> 1, n2 >> 1))>>1;
    if (!(is_even[0] || is_even[1]))
        return gcd(n1 - n2, n2);
    if (is_even[0])
        return gcd(n1 >> 1, n2);
    if (is_even[1])
        return gcd(n1, n2 >> 1);
}

void transform_to_fraction_core(char* str, long long& nominator, long long& denominator) {
    denominator = 1;
    nominator = 0;
    while (*str != '\0') {
        denominator *= 10;
        nominator = nominator * 10 + (int)(*str) - (int)'0';
        str++;
    }
    if (denominator > 1)
        denominator -= 1;
}

void transform_to_fraction(char* str, long long& int_part,
        long long& nominator, long long& denominator) {
    int_part = 0;
    while ((*str != '.') && (*str != '\0')) {
        int_part = int_part * 10 + (*str) - '0';
        str++;
    }
    if (*str == '\0') {
        nominator = 0;
        denominator = 1;
        return;
    }
    long long denominator_part = 1;
    long long nominator_part = 0;
    str++;
    long long part_num = 1;
    while ((*str != '(') && (*str != '\0')) {
        denominator_part *= 10;
        nominator_part = nominator_part * 10 + (int)(*str) - (int)'0';
        str++;
        part_num *= 10;
    }
    if (*str == '\0') {
        return ;
    }
    str ++;
    char* loop_part = new char[strlen(str)];
    char* tmp = loop_part;
    while (*str != ')') {
        *(tmp++) = (*str);
        str++;
    }
    *tmp = '\0';
    transform_to_fraction_core(loop_part, nominator, denominator);
    denominator *= part_num;
    int n1 = gcd(nominator, denominator);
    nominator /= n1;
    denominator /= n1;
    nominator = nominator_part * denominator + nominator * denominator_part;
    denominator *= denominator_part;
    int n2 = gcd(nominator, denominator);
    nominator /= n2;
    denominator /= n2;
}


int main() {
    long long nominator = 0;
    long long denominator = 0;
    long long int_part = 0;
    transform_to_fraction("33.3333(333333)", int_part,
        nominator, denominator);
    assert(int_part == 33);
    assert(nominator == 1);
    assert(denominator == 3);
}
