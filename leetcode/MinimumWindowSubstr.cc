/*
 * =====================================================================================
 *
 *       Filename:  MinimumWindowSubstr.cc
 *
 *    Description:  
        Given a string S and a string T, find the minimum window in S 
        which will contain all the characters in T in complexity O(n).

        For example,
        S = "ADOBECODEBANC"
        T = "ABC"

        Minimum window is "BANC".

        Note:
        If there is no such window in S that covers all characters in T, return the emtpy string "".

        If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/27 10:18:36
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
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int need_to_find[256];
        memset(need_to_find, 0, sizeof(need_to_find));
        for (string::iterator it = T.begin(); it != T.end(); it++)
            need_to_find[*it]++;
        int has_found[256];
        memset(has_found, 0, sizeof(has_found));
        
        int min_win_start = -1;
        int count = 0;
        int min_win_len = INT_MAX;
        for (int begin = 0, end = 0; end < S.length(); end++) {
            if (need_to_find[S[end]] == 0)
                continue;
            has_found[S[end]]++;
            if (has_found[S[end]] <= need_to_find[S[end]])
                count++;
            if (count == T.length()) {
                while ((need_to_find[S[begin]] == 0) || (
                    has_found[S[begin]] > need_to_find[S[begin]])){
                    if (has_found[S[begin]] > need_to_find[S[begin]])
                        has_found[S[begin]]--;
                    begin++;
                }
                if (end-begin+1 < min_win_len) {
                    min_win_len = end - begin + 1;
                    min_win_start = begin;
                }
            }
        }
        if (min_win_start == -1)
            return "";
        return S.substr(min_win_start, min_win_len);
    }
};



class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret;
        int ret_len = 0x7FFFFFFF;
        int p1 = -1;
        int p2 = -1;
        map<char, pair<int, int>> dict;
        int len = 0;
        for (string::iterator it = T.begin(); it != T.end(); it++) {
            if (dict.find(*it) == dict.end()) {
                dict.insert(pair<char, pair<int, int> >(*it, pair<int, int>(1, 0)));
                len ++;
            }
            else
                dict[*it].first++;
        }
        int count = 0;
        int i = 0;
        for (string::iterator it = S.begin(); it != S.end(); it++, i++) {
            if (dict.find(*it) == dict.end())
                continue;
            if (p1 == -1) {
                p1 = i;
                p2 = i;
            } else {
                p2 = i;
            }
            pair<int, int> &pa = dict[*it];
            if (pa.second != (pa.first - 1)) {
                pa.second++;
                continue;
            }
            count++;
            pa.second++;
            
            if (count != len)
                continue;
            if (p1 == p2) {
                if (ret_len != 1) {
                    ret = S.substr(p1, 1);
                    ret_len = 1;
                }
                break;
            }
            while (p1 < p2) {
                char c = S[p1];
                if (dict.find(c) != dict.end()) {
                    if (count != len)
                        break;
                    else {
                        if ((p2 - p1 + 1) < ret_len) {
                            ret_len = p2 - p1 + 1;
                            ret = S.substr(p1, ret_len);
                        }
                        pair<int, int> &pa = dict[c];
                        if (pa.second == pa.first)
                            count --;
                        pa.second --;
                        p1++;
                    } 
                } else {
                    p1 ++;
                }
            }
        }
        return ret;
    }
};

