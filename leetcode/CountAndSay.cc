/*
 * =====================================================================================
 *
 *       Filename:  CountAndSay.cc
 *
 *    Description:  
        The count-and-say sequence is the sequence of integers beginning as follows:
        1, 11, 21, 1211, 111221, ...

        1 is read off as "one 1" or 11.
        11 is read off as "two 1s" or 21.
        21 is read off as "one 2, then one 1" or 1211.

        Given an integer n, generate the nth sequence.

        Note: The sequence of integers will be represented as a string.
 
 *
 *        Version:  1.0
 *        Created:  2013/7/11 16:26:52
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
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string prev = "1";
        for (int i = 2; i <= n; i++) {
            string::iterator it = prev.begin();
            char c = *it;
            int count = 1;
            string next;
            it++;
            for (; it != prev.end(); it++) {
                if (*it == c)
                    count ++;
                else {
                    next.push_back(count + '0');
                    next.push_back(c);
                    c = *it;
                    count = 1;
                }
            }
            next.push_back(count + '0');
            next.push_back(c);            
            prev = next;
        }
        return prev;
    }
};

