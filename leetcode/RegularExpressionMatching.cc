/*
 * =====================================================================================
 *
 *       Filename:  RegularExpressionMatching.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/8/13 11:40:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
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
        if ((s == NULL) || (p == NULL))
            return false;
        int s_len = strlen(s);
        int p_len = strlen(p);
        vv_bool is_match(p_len + 1, v_bool(s_len + 1, false));
        is_match[0][0] = true;
        for (int pi = 1; pi <= p_len; pi++) {
            char pch = p[pi-1];
            if (is_match[pi-1][0]) {
                if ((pch == '*') || ((pi < p_len) && (p[pi] == '*')))
                    is_match[pi][0] = true;
            }
            
            if (pch == '*') {
                for (int si = 1; si <= s_len; si++) {
                    char c;
                    if (pi >= 2)
                        c = p[pi-2];
                    else
                        c = s[si-1];
                    if (c == '.') {
                        for (int k = si; k >= 0; k--) {
                            if (is_match[pi-1][k]) {
                                is_match[pi][si] = true;
                                break;
                            }
                        }
                    } else {
                        for (int k = si; k >= 0; k--) {
                            if (is_match[pi-1][k]) {
                                is_match[pi][si] = true;
                                break;
                            }
                            if ((k > 0) && (s[k-1] != c))
                                break;
                        }
                    }
                }                
            } else {
                if ((pi == p_len) || (p[pi] != '*')) {
                    for (int si = 1; si <= s_len; si++) {
                        char c = (p[pi-1] == '.') ? s[si-1] : p[pi-1];
                        if (is_match[pi-1][si-1] && (c == s[si-1]))
                            is_match[pi][si] = true;
                    }    
                } else { // p[pi] == '*';
                    for (int si = 1; si <= s_len; si++) {
                        char c = p[pi-1];
                        if (c == '.') {
                            for (int k = si; k >= 0; k--) {
                                if (is_match[pi-1][k]) {
                                    is_match[pi][si] = true;
                                    break;
                                }
                            }
                        } else {
                            for (int k = si; k >= 0; k--) {
                                if (is_match[pi-1][k]) {
                                    is_match[pi][si] = true;
                                    break;
                                }
                                if ((k > 0) && (s[k-1] != c))
                                    break;
                            }
                        }
                    }
                }
            }
        }
        return is_match[p_len][s_len];
    }
};
