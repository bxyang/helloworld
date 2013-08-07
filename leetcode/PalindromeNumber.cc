/*
 * =====================================================================================
 *
 *       Filename:  PalindromeNumber.cc
 *
 *    Description:  
        Determine whether an integer is a palindrome. Do this without extra space.

        Some hints:
        Could negative integers be palindromes? (ie, -1)

        If you are thinking of converting the integer to string, note the restriction of using extra space.

        You could also try reversing an integer. 
        However, if you have solved the problem "Reverse Integer", 
        you know that the reversed integer might overflow. How would you handle such case?

        There is a more generic way of solving this problem.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/7 9:54:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@!63.com
 *   Organization:  ict  
 *
 * =====================================================================================
 */

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
            return false;
        int div = 1;
        while (x / div >= 10)
            div *= 10;
        while (x > 9) {
            int l = x/div;
            x = x % div;
            int r = x%10;
            x = x/10;
            if (l != r)
                return false;
            div /= 100;
        }
        return true;
    }
};
