/*
 * =====================================================================================
 *
 *       Filename:  2-7-GCD.cc
 *
 *    Description:  max common divisor
 *
 *        Version:  1.0
 *        Created:  07/01/2013 03:42:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<utility>
#include<cassert>

int gcd1(int n1, int n2) {
    if (n2 == 0)
        return n1;
    if (n1 < n2) {
        std::swap(n1, n2);
    }
    return gcd1(n2, n1 % n2);
}

int gcd2(int n1, int n2) {
    if (n2 == 0)
        return n1;
    if (n1 < n2) {
        std::swap(n1, n2);
    }
    return gcd2(n1, n1 - n2);
}

int gcd3(int n1, int n2) {
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
        return (gcd3(n1 >> 1, n2 >> 1))>>1;
    if (!(is_even[0] || is_even[1]))
        return gcd3(n1 - n2, n2);
    if (is_even[0])
        return gcd3(n1 >> 1, n2);
    if (is_even[1])
        return gcd3(n1, n2 >> 1);
}

int main() {
    assert(gcd3(121, 11) == 11);
    return 0;
}
