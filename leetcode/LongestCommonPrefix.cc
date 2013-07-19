/*
 * =====================================================================================
 *
 *       Filename:  LongestCommonPrefix.cc
 *
 *    Description:  
        Write a function to find the longest common prefix string amongst an array of strings. 
 *
 *        Version:  1.0
 *        Created:  2013/7/18 16:17:36
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
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0)
            return string();
        return longestCommonPrefixCore(strs, 0, strs.size() - 1);
    }
    
    string longestCommonPrefixCore(vector<string> &strs, int start, int end) {
        if (start == end)
            return strs[start];
        int mid = (start + end) / 2;
        string s1 = longestCommonPrefixCore(strs, start, mid);
        string s2 = longestCommonPrefixCore(strs, mid+1, end);
        return longestCommonPrefixOfTwo(s1, s2);
        
    }
    
    string longestCommonPrefixOfTwo(string& s1, string& s2) {
        int len = (s1.length() < s2.length() ? s1.length() : s2.length());
        int i = 0;
        for (; i < len; i++) {
            if (s1[i] != s2[i])
                break;
        }
        return s1.substr(0, i);
    }
};

