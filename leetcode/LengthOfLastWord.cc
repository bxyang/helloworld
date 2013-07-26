/*
 * =====================================================================================
 *
 *       Filename:  LengthOfLastWord.cc
 *
 *    Description:  
        Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
        return the length of last word in the string.

        If the last word does not exist, return 0.

        Note: A word is defined as a character sequence consists of non-space characters only.

        For example, 
        Given s = "Hello World",
        return 5.
 *
 *        Version:  1.0
 *        Created:  2013/7/26 15:49:24
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
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == NULL)
            return 0;
        int last = 0;
        int now = 0;
        const char* p = s;
        while (*p != '\0'){
            if (*p == ' ') {
                last = (now != 0 ? now : last);
                now = 0;
            } else {
                now++;
            }
            p++;
        }
        return (now != 0 ? now : last);
    }
};

