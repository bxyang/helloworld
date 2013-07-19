/*
 * =====================================================================================
 *
 *       Filename:  3-1-2TelToWord.cc
 *
 *    Description:  convert tel number to word
 *
 *        Version:  1.0
 *        Created:  07/15/2013 10:55:49 AM
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

const char c[10][5] = {{""}, {""}, 
    {"ABC"}, {"DEF"}, {"GHI"}, {"JKL"}, 
    {"MNO"}, {"PQRS"}, {"TUV"}, {"WXYZ"}};

const int total_num[10] = {0, 0, 
                3, 3, 3, 3, 
                3, 4, 3, 4};


void print_words(char* num, int len) {
    int* word = new int[len+1];
    char* valid_num = new char[len+1];
    char* t_num = num;
    int* t_word = word;
    char* t_valid_num = valid_num;
    int n = len;
    while (n>=0) {
        if ((*t_num != '1') && (*t_num != '0')) {
            (*t_valid_num) = (*t_num);
            (*t_word) = 0;
            t_valid_num++;
            t_word++;
        } else {
            len --;
        }
        n--;
        t_num++;
    }
    *t_valid_num = '\0';
    while (true) {
        t_valid_num = valid_num;
        for (int i = 0; i < len; i++) {
            printf("%c", c[*t_valid_num - 48][word[i]]);
            t_valid_num++;
        }
        printf("\n");
        int k = len - 1;
        while (k>=0) {
            if (word[k] < (total_num[valid_num[k] - 48] - 1)) {
                word[k]++;
                break;
            } else {
                word[k] = 0;
                k--;
            }   
        }
        if (k < 0)
            break;
    }
    delete []word;
    delete []valid_num;
}

void print_words_recursive_core(char* valid_num, int len, char* word, int i);
void print_words_recursive(char* num, int len) {
    char* valid_num = new char[len+1];
    char* t_num = num;
    char* t_valid_num = valid_num;
    int n = len;
    while (n>=0) {
        if ((*t_num != '1') && (*t_num != '0')) {
            (*t_valid_num) = (*t_num);
            t_valid_num++;
        } else {
            len --;
        }
        n--;
        t_num++;
    }
    *t_valid_num = '\0';
    char* word = new char[len+1];
    print_words_recursive_core(valid_num, len, word, 0);
    delete []word;
    delete []valid_num;
}

void print_words_recursive_core(char* valid_num, int len, char* word, int i) {
    if (i == len) {
        word[i] = '\0';
        printf("%s\n", word);
        return;
    }
    int idx = (*valid_num) - 48;
    int n = total_num[idx];
    for (int j = 0; j < n; j++) {
        word[i] = c[idx][j];
        print_words_recursive_core(valid_num+1, len, word, i+1);
    }
}

int main() {
    //print_words("123", 3);
    print_words_recursive("123", 3);
}
