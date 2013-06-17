/*
 * =====================================================================================
 *
 *       Filename:  35.cc
 *
 *    Description:  first appeared character
 *
 *        Version:  1.0
 *        Created:  06/17/2013 09:39:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cassert>
#include<cstdlib>

char first_not_repeating_char(char* str) {
    assert(str != NULL);   
    unsigned int hash_table[256];
    for (int i = 0; i < 256; i++)
        hash_table[i] = 0;
    char* p = str;
    while (*p != '\0')
        hash_table[*(p++)]++;
    p = str;
    while (*p != '\0') {
        if (hash_table[*p] == 1)
            return *p;
        p++;
    }
    return '\0';
}

int main() {
    assert(first_not_repeating_char("abaccdeff") == 'b');   
    return 0;
}
