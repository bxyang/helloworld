/*
 * =====================================================================================
 *
 *       Filename:  Subsets.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/7 15:34:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include<cstdlib>
#include<cstdio>
#include<string.h>

void print_all_subsets_core(int* data, int next_data, char* subset, int next_pos) {
    while ((next_data < 128) && (data[next_data] == 0))
        next_data++;
    if (next_data == 128) {
        if (next_pos > 0) {
            subset[next_pos] = '\0';
            printf("%s\n", subset);
        }
        return;
    }
    int n = data[next_data];
    for (int i = 0; i <= n; i++) {
        memset(subset+next_pos, next_data, i);
        print_all_subsets_core(data, next_data+1, subset, next_pos+i);
    }
}

void print_all_subsets(char* str) {
    if (str == NULL)
        return;
    int len = 0;
    int data[128];
    memset(data, 0, sizeof(data));
    while (*str != '\0') {
        data[*str]++;
        len++;
        str++;
    }
    char* subset = new char[len+1];
    print_all_subsets_core(data, 0, subset, 0);
}

int main() {
    char* str = "KUXUN";
    print_all_subsets(str);
    return 0;
}
