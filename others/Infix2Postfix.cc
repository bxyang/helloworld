/*
 * =====================================================================================
 *
 *       Filename:  Infix2Postfix.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/14 16:30:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<stack>
#include<cstdlib>
#include<cstdio>
#include<string.h>


using namespace std;

void infix2postfix(char* infix, char* postfix);
int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        char infix[1000];
        char postfix[2000];
        gets(infix);
        //printf("%s\n", infix);
        infix2postfix(infix, postfix);
        //printf("\n%s\n", postfix);
        printf("%s\n", postfix);
    }

}

bool is_ge(char l, char r) {
    return (l=='*') || (l=='/') || (r=='+') || (r=='-');
}

void infix2postfix(char* infix, char* postfix) {
    stack<char> st;
    char* p = infix;
    char* q = postfix;

    while (*p != '=') {
        if ((*p == '+') || (*p == '-') || (*p == '*') || (*p == '/')) {
            while (!st.empty() && (st.top() != '(') && is_ge(st.top(), *p)) {
                *(q++) = ' ';
                *(q++) = st.top();
                st.pop();
            }
            *(q++) = ' ';
            st.push(*p);
        } else if (*p == '(') {
            st.push('(');
        } else if (*p == ')') {
            while (!st.empty() && (st.top() != '(')) {
                *(q++) = ' ';
                *(q++) = st.top();
                st.pop();
            }
            st.pop();
        } else {
            *(q++) = *p;
        }
        p++;
    }
    while (!st.empty()) {
        char c = st.top();
        if ((c != ')') && (c != '(')) {
            *(q++) = ' ';
            *(q++) = c;
        }
        st.pop();
    }
    *(q++) = ' ';
    *(q++) = '=';
    *q = '\0';
}

