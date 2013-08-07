/*
 * =====================================================================================
 *
 *       Filename:  LongestPalindromicSubstring.cc
 *
 *    Description:  
         Given a string S, find the longest palindromic substring in S. 
         You may assume that the maximum length of S is 1000, 
         and there exists one unique longest palindromic substring.
 *
 *        Version:  1.0
 *        Created:  2013/8/7 10:50:07
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
    typedef vector<vector<bool> > vvbool;
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        int ret = 1;
        int p1 = 0;
        int p2 = 0;
        vvbool flags = vvbool(len, vector<bool>(len, false));
        vvbool is_palin = vvbool(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++) {
            if (ret >= (len - i))
                break;
            for (int j = i+1; j <len; j++) {
                if(isPalindrome(s, flags, is_palin, i, j)) {
                    if (ret < (j-i+1)) {
                        p1 = i;
                        p2 = j;
                        ret = j-i+1;
                    }
                }
            }
        }
        return s.substr(p1, ret);
    }
    
    bool isPalindrome(string &s, vvbool &flags, vvbool &is_palin, int i, int j) {
        if (flags[i][j])
            return is_palin[i][j];
        flags[i][j] = true;
        if (s[i] != s[j]) {
            is_palin[i][j] = false;
            return false;
        }
        if ((i == j) || ((i+1) == j)) {
            is_palin[i][j] = true;
            return true;
        }
        bool ret = isPalindrome(s, flags, is_palin, i+1, j-1);
        is_palin[i][j] = ret;
        return ret;
    }
};

class Solution {
public:
    typedef vector<vector<bool> > vvbool;
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        int ret = 1;
        int p1 = 0;
        int p2 = 0;
        vvbool flags = vvbool(len, vector<bool>(len, false));
        vvbool is_palin = vvbool(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++) {
            if (ret >= (len - i))
                break;
            for (int j = len-1; j > (i+ret); j--) {
                if(isPalindrome(s, flags, is_palin, i, j)) {
                    if (ret < (j-i+1)) {
                        p1 = i;
                        p2 = j;
                        ret = j-i+1;
                    }
                    break;
                }
            }
        }
        return s.substr(p1, ret);
    }
    
    bool isPalindrome(string &s, vvbool &flags, vvbool &is_palin, int i, int j) {
        if (flags[i][j])
            return is_palin[i][j];
        flags[i][j] = true;
        if (s[i] != s[j]) {
            is_palin[i][j] = false;
            return false;
        }
        if ((i == j) || ((i+1) == j)) {
            is_palin[i][j] = true;
            return true;
        }
        bool ret = isPalindrome(s, flags, is_palin, i+1, j-1);
        is_palin[i][j] = ret;
        return ret;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        string ret = s.substr(0, 1);
        for (int i = 0; i < len - 1; i++) {
            string tmp = findLongest(s, i, i+1);
            if (tmp.length() > ret.length())
                ret = tmp;
            tmp = findLongest(s, i, i);
            if (tmp.length() > ret.length())
                ret = tmp;
        }
        return ret;
    }
    
    string findLongest(string& s, int left, int right) {
        while ((left >= 0) && (right < s.length())){
            if (s[left] != s[right])
                break;
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
};

