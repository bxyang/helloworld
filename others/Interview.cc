/*
 * =====================================================================================
 *
 *       Filename:  Prac.cc
 *
 *    Description:  several functions encountered commonly when participating interview 
 *
 *        Version:  1.0
 *        Created:  05/08/2013 02:57:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void* by_memcpy(void *dest, const void *src, size_t n);
char* by_strcpy(char *dest, const char *src);
char* by_itoa(int value, char *str, int radix);
const int cas_num = 3;


int main(){
    switch(cas_num){
        case 0:
        {
            char* d = (char* )malloc(10);
            char* s = "hello";
            by_memcpy(d, s, 3);
            d[5] = 'l';
            for(int i = 0; i < 5; i++){
                printf("%c", d[i]);
                if(d[i] == '\0'){
                    printf("%d ", i);
                }
            }
            printf("\n");
            printf("%s\n", d);
            break;
        }
        case 1:
        {
            char* d ;
            char* s = "hello";
            by_memcpy(d, s, 3);
            break;
        }
        case 2:
        {
            char s[4] = {'h', 'e', 'l', 'o'};
            char* tmp = s;
            int a = 15;
            char* d = (char* )malloc(10);
            //by_strcpy(d, s);
            //strcpy(d, s);
            printf("%s\n", tmp);
            break;
        }
        case 3:
        {
            char* d = (char* )malloc(10);
            unsigned int u = -1;
            // sprintf(d, "%x", u);
            printf("%s\n", by_itoa(16, d, 2));
            // printf("%d\n", sizeof(unsigned int));
            break;
        }
        default:
            break;
    }
    return 0;
}

void* by_memcpy(void *dest, const void *src, size_t n) {
    assert((dest != NULL) && (src != NULL)); // check NULL pointer
    char *dst = (char *)dest; // type convertion
    const char *tmp = (const char *)src;
    assert(!((dst >= tmp) && (dst < tmp + n))); // check overlap
    assert(!((dst <= tmp) && (tmp < dst + n)));
    while(n--){
        *(dst++) = *(tmp++);
    }
    return dest;
}

char* by_strcpy(char *dest, const char *src) {
    assert((dest != NULL) && (src != NULL)); // check NULL pointer
    char* dst_cpy = dest; // store dest head, for return
    while((*dest++ = *src++) != '\0'); // must copy '\0'
    return dst_cpy;
}
char* by_itoa(int value, char *str, int radix){
    assert(str != NULL);
    assert((radix >= 2) && (radix <=36));
    int start = 0;
    int length = 0;
    char* str_head = str;
    if(radix == 10 && value < 0){
        str[length++] = '-';
        value = -value;
        start = 1;
    }
    if(value == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str_head;
    }
    unsigned int divider = value;
    while(divider != 0){
        unsigned int remainder = divider % radix;
        if(remainder > 9){
            str[length++] = (char)(remainder + (int)'A');
        }
        else{
            str[length++] = (char)(remainder + (int)'0');
        }   
        divider = divider / radix;
    }
    int end = (start + length) / 2;
    for(int i = start; i < end; i++){
        char c = str[i];
        str[i] = str[length - 1 - i + start];
        str[length - 1 - i + start] = c;
    }
    str[length] = '\0';
    return str_head;
}
