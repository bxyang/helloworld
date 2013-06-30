/*
 * =====================================================================================
 *
 *       Filename:  ValidPalindrome.cc
 *
 *    Description: Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases. 
 *
 *        Version:  1.0
 *        Created:  2013/6/29 21:26:48
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
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s_len = s.size();
        int p1 = 0;
        int p2 = s_len - 1;
        while(p1 < p2) {
            char c1 = s[p1];
            if (!isAlphanumeric(c1)) {
                p1++;
                continue;
            }
            char c2 = s[p2];
            if (!isAlphanumeric(c2)) {
                p2--;
                continue;
            }
            int diff = c1 - c2;
            if ((diff == 0) || (diff == 32) || (diff == -32)) {
                p1++;
                p2--;
            }                
            else
                return false;
        }
        return true;
    }
    
    bool isAlphanumeric(char c) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        else
            return false;
    }
};

