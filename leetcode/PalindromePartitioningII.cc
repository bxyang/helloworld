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
        // -1 unknown
        vector<int> min_cut(s_len, -1);
        return minCut(s, 0, s_len - 1, min_cut);
    }
    
    int minCut(string& s, int start, int end, vector<int>& min_cut) {
        int ret = end - start;
        for (int i = end; i >= start; i--) {
            if (!is_palindrome(s, start, i))
                continue;
            if (i == end) {
                return 0;
            }
            int tmp;
            if (min_cut[i+1] != -1)
                tmp = min_cut[i+1];
            else {
                tmp = minCut(s, i+1, end, min_cut);
                min_cut[i+1] = tmp;
            }
            if (tmp == 0)
                return 1;
            if (ret > (tmp + 1))
                ret = tmp + 1;
        }
        return ret;
    }
    
    bool is_palindrome(string& s, int start, int end) {
        int p1 = start;
        int p2 = end;
        while (p1 < p2) {
            if (s[p1++] != s[p2--])
                return false;
        }
        return true;
    }
};

