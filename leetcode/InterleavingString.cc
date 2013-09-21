/*
 * =====================================================================================
 *
 *       Filename:  InterleavingString.cc
 *
 *    Description:  
        Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

        For example,
        Given:
        s1 = "aabcc",
        s2 = "dbbca",

        When s3 = "aadbbcbcac", return true.
        When s3 = "aadbbbaccc", return false.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/28 22:40:14
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
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int s1_len = s1.length();
        int s2_len = s2.length();
        int s3_len = s3.length();
        if ((s1_len + s2_len) != s3_len)
            return false;
        vector<vector<bool> > dp(s1_len+1, vector<bool>(s2_len+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= s1.length(); i++) {
            if (s1[i-1] == s3[i-1])
                dp[i][0] = true;
            else
                break;
        }

        for (int i = 1; i <= s2.length(); i++) {
            if (s2[i-1] == s3[i-1])
                dp[0][i] = true;
            else
                break;
        }
        for (int i = 1; i <= s1_len; i++) {
            for (int j = 1; j <= s2_len; j++) {
                int k = i - 1 + j - 1 + 1;
                if ((s3[k] == s2[j-1]) && (dp[i][j-1])) {
                    dp[i][j] = true;
                    continue;
                } 
                if ((s3[k] == s1[i-1]) && (dp[i-1][j]))
                    dp[i][j] = true;
            }
        }
        
        return dp[s1_len][s2_len];
    }
};


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((s1.length() == 0) && (s2.length() == 0)) {
            if (s3.length() == 0)
                return true;
            else
                return false;
        }
        
        if (s1.length() == 0) {
            return s2==s3;
        } 
        
        if (s2.length() == 0) {
            return s1==s3;
        }
        vector<vector<vector<bool> > > isSet = vector<vector<vector<bool> > >(
            s1.size(), vector<vector<bool> >(s2.size(), vector<bool>(s3.size(), false)));
        vector<vector<vector<bool> > > state = isSet;
        return isInterleave(state, isSet, s1, 0, s2, 0, s3, 0);
    }
    
    bool isInterleave(vector<vector<vector<bool> > > &state, 
        vector<vector<vector<bool> > > &isSet, 
        string s1, int p1, string s2, int p2, string s3, int p3) {
        if (p1 == s1.length())
            return s2.substr(p2) == s3.substr(p3);
        if (p2 == s2.length())
            return s1.substr(p1) == s3.substr(p3);
        if (p3 == s3.length())
            return false;       

        if (isSet[p1][p2][p3])
            return state[p1][p2][p3];
        
        isSet[p1][p2][p3] = true;
        char c = s3[p3];
        bool ret = false;
        if (s1[p1] == c)
            ret |= isInterleave(state, isSet, s1, p1+1, s2, p2, s3, p3+1);
        if (ret) {
            state[p1][p2][p3] = true;
            return true;
        }
        if (s2[p2] == c)
            ret |= isInterleave(state, isSet, s1, p1, s2, p2+1, s3, p3+1);

        state[p1][p2][p3] = ret;
        return ret;            
    }
};

