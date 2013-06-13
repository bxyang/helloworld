/*
 * =====================================================================================
 *
 *       Filename:  28.cc
 *
 *    Description:  permutation
 *
 *        Version:  1.0
 *        Created:  06/09/2013 04:48:22 PM
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
#include<utility>
#include<string.h>

void permutation(char* p_str, char* p_begin) {
    if ((p_str == NULL) || (p_begin == NULL))
        return;
    if (*p_begin == '\0') {
        printf("%s\n", p_str);
        return;
    }
    for (char* p = p_begin; *p != '\0'; p++) {
        std::swap(*p_begin, *p);
        permutation(p_str, p_begin + 1);
        std::swap(*p, *p_begin);
    }
}

int main() {
    char* pool = new char[4];
    memcpy(pool, "abc", 4);
    permutation(pool, pool);
    delete []pool;
    return 0;
}
