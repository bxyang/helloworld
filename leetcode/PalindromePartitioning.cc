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

