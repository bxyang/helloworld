/*
 * =====================================================================================
 *
 *       Filename:  2-2-Factorial.cc
 *
 *    Description:  factorial related questions
 *
 *        Version:  1.0
 *        Created:  06/26/2013 09:35:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cassert>

unsigned int factorial_num_of_zero_end1(unsigned int n) {
    unsigned int count = 0;
    for (unsigned int i = 5; i <= n; i++) {
        unsigned int t = i;
        while (t % 5 == 0) {
            count++;
            t = t/5;
        }
    }
    return count;
}

unsigned int factorial_num_of_zero_end2(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        n /= 5;
        count += n;
    }
    return count;
}


unsigned int factorial_num_of_zero_binary_end1(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        n = n >> 1;
        count += n;
    }
    return count;
}

unsigned int factorial_num_of_zero_binary_end2(unsigned int n) {
    unsigned int count = 0;
    unsigned int x = 0x1;
    unsigned int nt = n;
    while (nt) {
        count += (nt & x);
        nt = nt >> 1;
    }
    return (n - count);
}

int main() {
    assert(factorial_num_of_zero_end1(68) == factorial_num_of_zero_end2(68));
    assert(factorial_num_of_zero_binary_end1(68) == factorial_num_of_zero_binary_end2(68));
    return 0;
}
