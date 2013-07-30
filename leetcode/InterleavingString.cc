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

