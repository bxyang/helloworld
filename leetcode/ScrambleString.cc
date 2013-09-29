/*
 * =====================================================================================
 *
 *       Filename:  ScrambleString.cc
 *
 *    Description:  
        Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

        Below is one possible representation of s1 = "great":

            great
           /    \
          gr    eat
         / \    /  \
        g   r  e   at
                   / \
                  a   t
        To scramble the string, we may choose any non-leaf node and swap its two children.

        For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

            rgeat
           /    \
          rg    eat
         / \    /  \
        r   g  e   at
                   / \
                  a   t
        We say that "rgeat" is a scrambled string of "great".

        Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

            rgtae
           /    \
          rg    tae
         / \    /  \
        r   g  ta  e
               / \
              t   a
        We say that "rgtae" is a scrambled string of "great".

        Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 *
 *
 *        Version:  1.0
 *        Created:  2013/9/29 12:32:36
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
    
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, map<string, bool> > states;
        if (! containsSameChar(s1, s2))
            return false;
        return isScrambleCore(s1, s2, states);
    }
    
    bool isScrambleCore(string s1, string s2, map<string, map<string, bool> > &states) {
        if ((states.find(s1) != states.end()) && (states[s1].find(s2) != states[s1].end()))
            return states[s1][s2];
        int n = s1.length();
        if (n < 2)
            return true;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            string str1 = s1.substr(0, i);
            string str2 = s2.substr(0, i);
            string str3 = s2.substr(n-i, i);
            if (containsSameChar(str1, str2) && isScrambleCore(str1, str2, states) && 
                isScrambleCore(s1.substr(i, n-i), s2.substr(i, n-i), states)) {
                flag = true;
                break;
            }
            if (containsSameChar(str1, str3) && isScrambleCore(str1, str3, states) && 
                isScrambleCore(s1.substr(i, n-i), s2.substr(0, n-i), states)) {
                flag = true;
                break;
            }
        }
        
        if (states.find(s1) == states.end()) {
            map<string, bool> tmp;
            tmp.insert(pair<string, bool>(s2, flag));
            states.insert(pair<string, map<string, bool> >(s1, tmp));
        } else {
            states[s1].insert(pair<string, bool>(s1, flag));
        }
        return flag;
    }
    
    bool containsSameChar(string &s1, string &s2) {
        int hash_table[128] = {0};
        for (string::iterator it = s1.begin(); it != s1.end(); it++)
            hash_table[*it]++;
        for (string::iterator it = s2.begin(); it != s2.end(); it++) {
            if (hash_table[*it] == 0)
                return false;
            hash_table[*it]--;
        }
        return true;
    }
};
