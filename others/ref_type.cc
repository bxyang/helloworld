/*
 * =====================================================================================
 *
 *       Filename:  ref_type.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/7 20:47:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cstdio>


int foo(int& para) {
    para = 10;
    return -1;
}

unsigned short hash(unsigned short key) {
    return (key << 8 >> 8) % 256;
}
int main() {
    int n = 0;
    const unsigned int u = 10;
    n = foo(n);
    while (n < u)
        n++;
    if (n > u)
        n = 100;
    if (n==u)
        n = 200;
    printf("%d\n", n);
    printf("%d\n", -1);
    printf("%d\n", hash(16));
    printf("%d\n", hash(256));
    return 0;
}
