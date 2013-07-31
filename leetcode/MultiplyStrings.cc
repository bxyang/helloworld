/*
 * =====================================================================================
 *
 *       Filename:  MultiplyStrings.cc
 *
 *    Description:  
        Given two numbers represented as strings, return multiplication of the numbers as a string.

        Note: The numbers can be arbitrarily large and are non-negative.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/31 13:11:04
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
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        string ret = "0";
        for (string::reverse_iterator it1 = num1.rbegin(); it1 != num1.rend(); it1++, i++) {
            int c = 0;
            int n1 = (*it1) - 48;
            int n2;
            string s(i, '0');
            for (string::reverse_iterator it2 = num2.rbegin(); it2 != num2.rend(); it2++) {
                n2 = (*it2) - 48;
                int r = n2*n1+c;
                c = r / 10;
                s = char(r%10 + 48) + s;
            }
            if (c != 0)
                s = char(c + 48) + s;
            ret = sum(ret, s);
        }
        i = 0;
        for (; i < ret.length(); i++)
            if (ret[i] != '0')
                break;
        if (i == ret.length())
            return "0";
        else
            return ret.substr(i);
    }
    
    
    string sum(string num1, string num2) {
        string ret;
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        int c = 0;
        for (; (p1 > -1) && (p2 > -1); p1--, p2--) {
            int n = num1[p1] - 48 + c + num2[p2] - 48;
            c = n / 10;
            ret = char(n%10 + 48)+ ret;
        }
        if ((p1 == -1) && (p2 == -1)) {
            if (c != 0)
                ret = char(c + 48)+ ret;
            return ret;
        }
        string &num = (p1 == -1) ? num2 : num1;
        p1 = (p1 == -1) ? p2 : p1;
        while ((p1 > -1) && (c !=0 )) {
            int n = num[p1] - 48 + c;
            c = n/10;
            ret = char(n%10 + 48)+ ret;
            p1--;
        }
        
        if (c == 0) {
            if (p1 != -1)
                ret = num.substr(0, p1 + 1)+ ret;
        } else {
            if (c != 0)
                ret = char(c + 48)+ ret;
        }
        return ret;
    }
};
