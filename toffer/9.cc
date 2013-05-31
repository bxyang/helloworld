/*
 * =====================================================================================
 *
 *       Filename:  9.cc
 *
 *    Description:  fibonacci
 *
 *        Version:  1.0
 *        Created:  05/31/2013 03:40:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cassert>
#include<stdexcept>

int fib_recursive(int n) {
    if (n < 0)
        throw std::runtime_error("invalid arg!");
    if (n < 2)
        return n;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

int fib(int n) {
    if (n < 0)
        throw std::runtime_error("invalid arg!");
    if (n < 2)
        return n;
    int f0 = 0;
    int f1 = 1;
    for (int i = 2; i <= n; i++) {
        int t = f1;
        f1 = f0 + f1;
        f0 = t;
    }
    return f1;
}

int main() {
    for (int i = 0; i < 5; i++)
        assert(fib(i) == fib_recursive(i));
    return 0;
}
