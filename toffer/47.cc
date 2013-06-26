/*
 * =====================================================================================
 *
 *       Filename:  47.cc
 *
 *    Description:  add
 *
 *        Version:  1.0
 *        Created:  06/25/2013 04:26:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


int add(int a, int b) {
    int sum;
    int n1 = a;
    int n2 = b;
    int carry;
    do {
        sum = (n1 ^ n2);
        carry = (n1 & n2) >> 1;
        n1 = sum;
        n2 = carry;
    } while(carry != 0) ;
    return sum;
}

int main() {
    return 0;
}
