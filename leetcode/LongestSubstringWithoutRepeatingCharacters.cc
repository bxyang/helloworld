/*
 * =====================================================================================
 *
 *       Filename:  LongestSubstringWithoutRepeatingCharacters.cc
 *
 *    Description:  
         Given a string, find the length of the longest substring without repeating characters. 
         For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
         which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 *        Version:  1.0
 *        Created:  2013/8/7 16:11:59
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
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dic(256, -1);
        int i = 0;
        int p1 = 0;
        int ret = 0;
        for (; i < s.length(); i++) {
            int c = (int)s[i];
            if (dic[c] == -1)
                dic[c] = i;
            else {
                ret = (i-p1) > ret ? (i-p1):ret;
                int p2 = dic[c];
                for (int j = p1; j < p2; j++)
                    dic[s[j]] = -1;
                p1 = p2+1;
                dic[c] = i;
            }
        }
        ret = (s.length()-p1) > ret ? (s.length()-p1):ret;
        return ret;
    }
};
