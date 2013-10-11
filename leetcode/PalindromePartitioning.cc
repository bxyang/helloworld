/*
 * =====================================================================================
 *
 *       Filename:  PalindromePartitioning.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/6/27 21:58:04
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
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int n = s.length();
        vector<vector<bool> > dp(n, vector<bool>(n ,false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            for (int j = i-1, k = i + 1; (j >= 0) && (k < n); j--, k++) {
                if (s[j] == s[k])
                    dp[j][k] = true;
                else
                    break;
            }
            for (int j = i, k = i+1; (j >= 0) && (k < n); j--, k++) {
                if (s[j] == s[k])
                    dp[j][k] = true;
                else
                    break;
            }
        }
        
        vector<vector<string> > ret;
        vector<string> item;
        dp_partiton_helper(ret, dp, s, 0, item);
        return ret;
    }
    
    void dp_partiton_helper(vector<vector<string> > &ret, vector<vector<bool> > &dp, string &s, 
            int i, vector<string> &item) {
        const int n = s.length();
        if (i == s.size()) {
            ret.push_back(item);
            return;
        }
        
        for (int j = i; j < n; j++) {
            if (!dp[i][j])
                continue;
            item.push_back(s.substr(i, j- i + 1));
            dp_partiton_helper(ret, dp, s, j+1, item);
            item.pop_back();
        }
        return;
    } 
};



class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> ret;
        int s_len = s.size();
        for (int i = 0; i < s_len; i++) {
            string s1 = s.substr(0, i+1);
            if (!is_palindrome(s1))
                continue;
            if (i == (s_len - 1)) {
                vector<string> t_vec;
                t_vec.push_back(s1);
                ret.push_back(t_vec);
                continue;
            }
            vector<vector<string>> tmp = partition(s.substr(i+1));
            if (!(tmp.size() > 0))
                continue;
            for(vector<vector<string>>::iterator it = tmp.begin(); it != tmp.end(); it++) {
                if ((*it).size() > 0) {
                    vector<string> t_vec;
                    t_vec.push_back(s1);
                    for (vector<string>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
                        t_vec.push_back(*it2);
                    ret.push_back(t_vec);
                }
            }
        }
        return ret;
    }
    
    bool is_palindrome(string s) {
        int s_len = s.size();
        for (int i = 0; i < s_len/2; i++) {
            if (s[i] != s[s_len -1 - i])
                return false;
        }
        return true;
    }
};

