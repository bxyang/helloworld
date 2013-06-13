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
#include<string.h>

void permutation(char* result, char* pool, int pos, int n) {
    if (pos == n)
        printf("%s\n", result);
    int pool_len = strlen(pool);
    for (int i = 0; i < pool_len; i++) {
        result[pos] = pool[i];
        char* remain_pool = new char[pool_len];
        if (i > 0)
            memcpy(remain_pool, pool, i);
        memcpy(remain_pool + i, pool + i + 1, pool_len - i - 1);
        remain_pool[pool_len] = '\0';
        permutation(result, remain_pool, pos + 1, n);
    }
    
}

int main() {
    char* pool = new char[4];
    memcpy(pool, "abc", 4);
    char* result = new char[4];
    result[3] = '\0';
    permutation(result, pool, 0, 3);
    return 0;
}
