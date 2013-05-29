/*
 * =====================================================================================
 *
 *       Filename:  4.cc
 *
 *    Description:  replace blank to %20
 *
 *        Version:  1.0
 *        Created:  05/29/2013 10:50:07 AM
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
#include<cstring>

void replace_blank(char* str) {
    int blank_num = 0;
    int str_len = 0;
    char* p = str;
    while (*p != '\0') {
        if (*p == ' ')
            blank_num ++;
        str_len ++;
        p++;
    }
    char* q = p;
    p += blank_num * 2;
    while ( q >= str) {
        if (*q != ' ')
            *(p--) = *(q--);
        else {
            *(p--) = '0';
            *(p--) = '2';
            *(p--) = '%';
            q--;
        }
    }
}

int main() {
    char* p = new char[100];
    strcpy(p, " i am a boy ");
    replace_blank(p);
    printf("%s\n", p);
    return 0;
}
