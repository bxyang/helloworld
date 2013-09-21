/*
 * =====================================================================================
 *
 *       Filename:  WildcardMatching.cc
 *
 *    Description:  
        Implement wildcard pattern matching with support for '?' and '*'.

        '?' Matches any single character.
        '*' Matches any sequence of characters (including the empty sequence).

        The matching should cover the entire input string (not partial).

        The function prototype should be:
        bool isMatch(const char *s, const char *p)

        Some examples:
        isMatch("aa","a") ? false
        isMatch("aa","aa") ? true
        isMatch("aaa","aa") ? false
        isMatch("aa", "*") ? true
        isMatch("aa", "a*") ? true
        isMatch("ab", "?*") ? true
        isMatch("aab", "c*a*b") ? false
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/13 17:26:03
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
    typedef vector<vector<bool> > vv_bool;
    typedef vector<bool> v_bool;
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((s == NULL) && (p == NULL))
            return true;
        if ((s == NULL) || (p == NULL))
            return false;
        int s_len = strlen(s);
        int p_len = strlen(p);
        v_bool is_match1(s_len+1, false);
        v_bool is_match2 = is_match1;
        is_match1[0] = true;
        for (int pi = 0; pi < p_len; pi++) {
            if ((p[pi] == '*') && is_match1[0])
                is_match2[0] = true;
            char p_ch = p[pi];
            if (p_ch == '*') {
                int si = 0;
                for (; si <= s_len; si++ ) {
                    if (is_match1[si])
                        break;
                }
                for (; si <= s_len; si++)
                    is_match2[si] = true;
            } else {
                for (int si = 1; si <= s_len; si++) {
                    char c = (p_ch == '?' ? s[si-1] : p_ch);
                    if (is_match1[si-1] && (c == s[si-1]))
                        is_match2[si] = true;
                }
            }
            is_match1 = is_match2;
            is_match2 = v_bool(s_len+1, false);
        }
        return is_match1[s_len];
    }
};


class Solution {
public:
    typedef vector<vector<bool> > vv_bool;
    typedef vector<bool> v_bool;
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((s == NULL) && (p == NULL))
            return true;
        if ((s == NULL) || (p == NULL))
            return false;
        int s_len = strlen(s);
        int p_len = 0;
        int non_asterisk_num = 0;
        const char* tmp_p = p;
        while (*tmp_p != '\0') {
            if (*tmp_p != '*')
                non_asterisk_num++;
            p_len++;
            tmp_p++;
        }
        
        if (non_asterisk_num > s_len)
            return false;
        vv_bool is_match = vv_bool(2, v_bool(s_len+1, false));
        is_match[0][0] = true;
        bool flag = 0;
        for (int pi = 0; pi < p_len; pi++) {
            if ((p[pi] == '*') && is_match[flag][0])
                is_match[!flag][0] = true;
            char p_ch = p[pi];
            if (p_ch == '*') {
                while (pi < p_len) {
                    if (p[pi] == '*')
                        pi++;
                    else
                        break;
                }
                pi--;
                int si = 0;
                for (; si <= s_len; si++ ) {
                    if (is_match[flag][si])
                        break;
                }
                for (; si <= s_len; si++)
                    is_match[!flag][si] = true;
            } else {
                for (int si = 1; si <= s_len; si++) {
                    char c = (p_ch == '?' ? s[si-1] : p_ch);
                    if (is_match[flag][si-1] && (c == s[si-1]))
                        is_match[!flag][si] = true;
                }
            }
            for (int i = 0; i <= s_len; i++)
                is_match[flag][i] = false;
            flag = !flag;
        }
        return is_match[flag][s_len];
    }
};

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*p == '\0')
            return *s == '\0';
        if (*p == '*') {
            while (*s != '\0') {
                if (isMatch(s, p+1))
                    return true;
                s++;
            }
            return isMatch(s, p+1);
        } else {
            if ( (*s != '\0') && ((*p == '?') || (*p == *s)))
                return isMatch(s+1, p+1);
            return false;
        }
    }
};
