/*
 * =====================================================================================
 *
 *       Filename:  LongestCommonSubstring.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/10 19:33:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<string.h>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

int longest_common_substring(char* s1, char* s2) {
    //int len1 = strlen(s1);
    //int len2 = strlen(s2);
    int g[2][100000+1];
    g[0][0] = 0;
    g[1][0] = 0;
    //memset(g[0], 0, sizeof(int)*(100000+1));
    const char* p1 = s1;
    const char* p2 = s2;
    int ret = 0;
    bool flag = 0;
    for (int i = 1; *p1 != '\0'; i++, p1++) {
        p2 = s2;
        for (int j = 1; *p2 != '\0'; j++, p2++) {
            if (*p1 == *p2) {
                g[!flag][j] = g[flag][j-1] + 1;
                ret = (ret < g[!flag][j] ? g[!flag][j] : ret); 
            } else {
                g[!flag][j] = 0;
            } 
        }
        flag = (!flag);
    }
    return ret;
}

int cmp1(const void* s1, const void* s2) {
    return strcmp(*((const char**)s1), *((const char**)s2));
    //return strcmp((const char*)s1, (const char*)s2);
}

bool cmp2( char *s1,char *s2) {
    return strcmp((const char*)s1, (const char*)s2) <= 0;
}

int longest_common_substring2(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char* str = new char[len1+len2+2];
    strcpy(str, s1);
    char z[2];
    z[0] = -128;
    z[1] = '\0';
    strcpy(str+len1, z);
    strcpy(str+len1+1, s2);
    char** suf = (char**)new int[len1+len2+1];
    char* p1 = str;
    for (int i = 0; *p1 != '\0'; i++, p1++) {
        suf[i] = p1;
    }
    qsort(suf, len1+len2+1, 4, cmp1);
    //sort(suf, suf+len1+len2+1, cmp2);
    int ret = 0;
    for (int i = 1; i < len1+len2+1; i++) {
        char* q1 = suf[i-1];
        char* q2 = suf[i];
        int n = 0;
        while ((*q1 != '\0') && (*q2 != '\0') && (*q1 != -128) && (*q2 != -128)) {
            if (*q1 == *q2)
                n++;
            else
                break;
            q1++;
            q2++;
        }
        if (n <= ret)
            continue;
        if ((*q1 == '\0') || (*q2 == '\0')) {
            char* t = (*q1 == '\0' ? q2 : q1);
            while (*t != '\0') {
                if (*t == -128) {
                    ret = n;
                    break;
                }
                t++;
            }
        } else {
            char* t = (*q1 == -128 ? q2 : q1);
            while (*t != '\0') {
                if (*t == -128)
                    break;
                t++;
            }
            if (*t == '\0')
                ret = n;
        }
    }
    return ret;
}

int main() {
    char s1[100001];
    char s2[100001];
    scanf("%s\n", s1);
    scanf("%s", s2);
    int ret = longest_common_substring2(s1, s2);
    printf("%d\n", ret);
    return 0;
}
