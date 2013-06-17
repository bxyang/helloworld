/*
 * =====================================================================================
 *
 *       Filename:  33.cc
 *
 *    Description:  sort array to get min number
 *
 *        Version:  1.0
 *        Created:  06/17/2013 07:30:43 PM
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

const int g_max_len = 10;

int compare_part(const char* sp1, const char* sp2, const char* lp1);

int compare(const void* p1, const void* p2) {
    const char* s1 = *((const char**)p1);
    const char* s2 = *((const char**)p2);
    while ((*s1 != '\0') && (*s2 != '\0')) {
        if (*s1 < *s2)
            return -1;
        else if(*s1 > *s2)
            return 1;
        s1++;
        s2++;
    }
    if ((*s1 == '\0') && (*s2 == '\0'))
        return 0;
    if (*s1 == '\0')
        return -compare_part(s2, *((const char**)p1), *((const char**)p2));
    else
        return compare_part(s1, *((const char**)p2), *((const char**)p1));
}

// strlen(sp1) < strlen(lp1)
// strlen(sp1) + strlen(sp2) = strlen(lp1)
int compare_part(const char* sp1, const char* sp2, const char* lp1) {
    while (*sp1 != '\0') {
        if (*sp1 < *lp1)
            return -1;
        else if(*sp1 > *lp1)
            return 1;
        sp1++;
        lp1++;
    }
    while (*sp2 != '\0') {
        if (*sp2 < *lp1)
            return -1;
        else if(*sp2 > *lp1)
            return 1;
        sp2++;
        lp1++;
    }
    return 0;
}

void print_min(int* numbers, int length) {
    if ((numbers == NULL) || (length < 1))
        return;
    char** str_numbers = (char**)(new int[length]);
    for (int i = 0; i < length; i++) {
        str_numbers[i] = new char[g_max_len];
        sprintf(str_numbers[i], "%d", numbers[i]);
    }
    qsort(str_numbers, length, sizeof(char*), compare);
    for (int i = 0; i < length; i++) {
        printf("%s", str_numbers[i]);
        delete [] (str_numbers[i]);
    }
    printf("\n");
    delete [] str_numbers;
}

int main() {
    int data[3] = {3, 32, 321};
    print_min(data, 3);
    return 0;
}
