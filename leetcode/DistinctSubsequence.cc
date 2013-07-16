/*
 * =====================================================================================
 *
 *       Filename:  DistinctSubsequence.cc
 *
 *    Description:  
        Given a string S and a string T, count the number of distinct subsequences of T in S.

        A subsequence of a string is a new string which is formed from the original string by 
        deleting some (can be none) of the characters without disturbing the relative positions
        of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

        Here is an example:
        S = "rabbbit", T = "rabbit"
         
 *
 *        Version:  1.0
 *        Created:  2013/7/16 16:00:48
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
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // key = s_len * s.length() + t_len
        map<int, int> f;
        return numDistinctCore(S, S.length(), T, T.length(), f, S.length());    
    }
    
    int numDistinctCore(string S, int s_len, string T, int t_len, map<int, int>& f, const int k) {
        if ((t_len == 0) || (s_len == 0))
            return 0;
        int key = s_len * k + t_len;
        if(f.find(key) != f.end())
            return f[key];
        int ret = 0;
        if (t_len == 1) {
            for (int i = 0; i < s_len; i++) {
                if (S[i] == T[0])
                    ret ++;
            }
        } else {
            for (int i = 0; i < s_len; i++) {
                if (S[i] == T[0])
                    ret += numDistinctCore(S.substr(i+1), s_len - i - 1, T.substr(1), t_len - 1, f, k);
            }
        }
        f[key] = ret;
        return ret;
    }
};

