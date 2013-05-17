/*
 * =====================================================================================
 *
 *       Filename:  Test.cc
 *
 *    Description:  Given string string str1, 
 *                  check whether str2 or its cylic shift contain str1 
 *
 *        Version:  1.0
 *        Created:  05/17/2013 03:27:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<string.h>
#include<assert.h>
#include<stdio.h>

bool strstr_cylic1(char* src, char* dest);
bool strstr_cylic2(char* src, char* dest);

int main() {
    char src[] = "CDAA";
    char dest[] = "AABBCD";
    assert(strstr_cylic1(src, dest));
    assert(strstr_cylic2(src, dest));
    return 0;
}

bool strstr_cylic1(char* src, char* dest) {
    int length = strlen(dest);
    for (int i = 0; i < length; i++) {
        char c = dest[0];
        int n = length - 1;
        for (int j = 0; j < n; j++)
            dest[j] = dest[j+1];
        dest[n] = c;
        if (strstr(dest, src) != NULL)
            return true;
    }
    return false;
}
bool strstr_cylic2(char* src, char* dest) {
    int length = strlen(dest);
    bool ret = false;
    if (strlen(src) > length)
        return ret;
    int n = 2*length + 1;
    char* p = new char[n];
    snprintf(p, n, "%s%s", dest, dest);
    if (strstr(p, src) != NULL)
        ret = true;
    delete []p;
    return ret;
}
