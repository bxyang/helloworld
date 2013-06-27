/*
 * =====================================================================================
 *
 *       Filename:  PalindromePartitioningII.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/6/27 23:12:32
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
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s_len = s.size();
        vector<int> tmp(s_len, -1);
        vector<vector<int>> is_pal(s_len, tmp);
        return minCut(s, 0, s.size() - 1, is_pal);
    }
    
    int minCut(string s, int start, int end, vector<vector<int>>& is_pal) {
        // 0 false
        // 1 true
        // -1 unknown
        int ret = end - start;
        for (int i = start; i <= end; i++) {
            string s1 = s.substr(start, i - start + 1);
            bool flag;
            int t = is_pal[start][i];
            if(t != -1)
                flag = t;
            else {
                flag = is_palindrome(s1);
                is_pal[start][i] = (int)flag;
            }
            if (!flag)
                continue;
            if (i == end) {
                return 0;
            }
            int tmp = minCut(s, i+1, end, is_pal);
            if (ret > (tmp + 1))
                ret = tmp + 1;
        }
        return ret;
    }
    
    inline bool is_palindrome(string s) {
        int s_len = s.size();
        int n1 = s_len / 2;
        int n2 = s_len -1;
        for (int i = 0; i < n1; i++) {
            if (s[i] != s[n2 - i])
                return false;
        }
        return true;
    }
};

