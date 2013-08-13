/*
 * =====================================================================================
 *
 *       Filename:  LongestValidParentheses.cc
 *
 *    Description:  
        Given a string containing just the characters '(' and ')', 
        find the length of the longest valid (well-formed) parentheses substring.

        For "(()", the longest valid parentheses substring is "()", which has length = 2.

        Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/13 15:03:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict  
 *
 * =====================================================================================
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st_ch;
        stack<int> st_idx;
        st_ch.push(')');
        st_idx.push(-1);
        int ret = 0;
        int i = 0;
        for (string::iterator it = s.begin(); it != s.end(); it++, i++) {
            if (*it == '(') {
                st_ch.push('(');
                st_idx.push(i);
            } else {
                char top_ch = st_ch.top();
                int top_idx = st_idx.top();
                if (top_ch == ')') {
                    st_ch.push(')');
                    st_idx.push(i);
                } else {
                    st_ch.pop();
                    st_idx.pop();
                    ret = ret > i - st_idx.top() ? ret : i - st_idx.top();
                }
            }
        }
        return ret;
    }
};
