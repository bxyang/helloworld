/*
 * =====================================================================================
 *
 *       Filename:  RemoveComments.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/18 10:47:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>

enum FA_STATE {
    FA_STATE_NUM = 9,
    FA_NORMAL = 0,
    FA_SINGLE_SLASH,
    FA_DOUBLE_SLASH,
    FA_SINGLE_QUOTE,
    FA_DOUBLE_QUOTE,
    FA_SQ_BSLASH,
    FA_DQ_BSLASH,
    FA_SLASH_STAR,
    FA_STAR
};


char trans[FA_STATE_NUM][128];

void init_trans() {
    memset(trans[FA_NORMAL], FA_NORMAL, sizeof(char)*128);
    trans[FA_NORMAL]['/'] = FA_SINGLE_SLASH;
    trans[FA_NORMAL]['\''] = FA_SINGLE_QUOTE;
    trans[FA_NORMAL]['\"'] = FA_DOUBLE_QUOTE;

    memset(trans[FA_SINGLE_SLASH], FA_NORMAL, sizeof(char)*128);
    trans[FA_SINGLE_SLASH]['/'] = FA_DOUBLE_SLASH;
    trans[FA_SINGLE_SLASH]['*'] = FA_SLASH_STAR;

    memset(trans[FA_DOUBLE_SLASH], FA_DOUBLE_SLASH, sizeof(char)*128);
    trans[FA_DOUBLE_SLASH]['\n'] = FA_NORMAL;

    memset(trans[FA_SINGLE_QUOTE], FA_SINGLE_QUOTE, sizeof(char)*128);
    trans[FA_SINGLE_QUOTE]['\''] = FA_NORMAL;
    trans[FA_SINGLE_QUOTE]['\\'] = FA_SQ_BSLASH;

    memset(trans[FA_DOUBLE_QUOTE], FA_DOUBLE_QUOTE, sizeof(char)*128);
    trans[FA_DOUBLE_QUOTE]['\"'] = FA_NORMAL;
    trans[FA_DOUBLE_QUOTE]['\\'] = FA_DQ_BSLASH;


    memset(trans[FA_SQ_BSLASH], FA_SINGLE_QUOTE, sizeof(char)*128);

    memset(trans[FA_DQ_BSLASH], FA_DOUBLE_QUOTE, sizeof(char)*128);

    memset(trans[FA_SLASH_STAR], FA_SLASH_STAR, sizeof(char)*128);
    trans[FA_SLASH_STAR]['*'] = FA_STAR;

    memset(trans[FA_STAR], FA_SLASH_STAR, sizeof(char)*128);
    trans[FA_STAR]['/'] = FA_NORMAL;
}

int main(int argc, char* argv[]) {
    init_trans();
    freopen (argv[1], "r", stdin);
    char c;
    FA_STATE state = FA_NORMAL;
    while (scanf("%c", &c) != EOF) {
        switch(state) {
        case FA_NORMAL:
            state = (FA_STATE)trans[state][c];
            if (state != FA_SINGLE_SLASH)
                printf("%c", c);
            break;
        case FA_SINGLE_SLASH:
            state = (FA_STATE)trans[state][c];
            if (state == FA_NORMAL)
                printf("%c%c", '/', c);
            break;
        case FA_DOUBLE_SLASH:
            state = (FA_STATE)trans[state][c];
            if (state == FA_NORMAL)
               printf("\n");
            break;
        case FA_SLASH_STAR:
            state = (FA_STATE)trans[state][c];
            break;
        case FA_STAR:
            state = (FA_STATE)trans[state][c];
            break;
        default:
            state = (FA_STATE)trans[state][c];
            printf("%c", c);
        }
    }
    fclose(stdin);
    return 0;
}



