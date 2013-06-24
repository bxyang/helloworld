/*
 * =====================================================================================
 *
 *       Filename:  42.cc
 *
 *    Description:  reverse words order in sentence
 *
 *        Version:  1.0
 *        Created:  06/24/2013 10:03:09 AM
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
#include<cassert>
#include<string.h>
#include<utility>


void reverse_word(char* pstart, char* pend) {
    assert((pstart != NULL) && (pend != NULL));
    while (pstart < pend){
        std::swap(*pstart, *pend);
        pstart++;
        pend--;
    }
}

void reverse_words_order(char* str) {
    assert(str != NULL);
    int len = strlen(str);
    reverse_word(str, str + (len - 1));
    char* pstart = str;
    char* pend = str;
    while (*str != '\0') {
        if (*str == ' ') {
            reverse_word(pstart, pend);
            str++;
            pstart = str;
            pend = str;
        }
        else{
            pend = str;
            str++;
        }
    }
}

void left_rotate_str(char* str, int n) {
    if((str == NULL) || (n < 0))
        return;
    int len = strlen(str);
    reverse_word(str, str + (len - 1));
    if (n > len)
        return;
    reverse_word(str, str + (len - n) - 1);
    reverse_word(str + (len - n), str + (len - 1));
}

int main() {
    char* str = new char[20];
    strcpy(str, "i am a boy");
    reverse_words_order(str);
    printf("%s\n", str);
    strcpy(str, "abcdef");
    left_rotate_str(str, 0);
    printf("%s\n", str);
}
