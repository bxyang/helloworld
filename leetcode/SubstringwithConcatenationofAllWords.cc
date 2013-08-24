/*
 * =====================================================================================
 *
 *       Filename:  SubstringwithConcatenationofAllWords.cc
 *
 *    Description:  
        You are given a string, S, and a list of words, L, that are all of the same length. 
        Find all starting indices of substring(s) in S 
        that is a concatenation of each word in L exactly once and without any intervening characters.

        For example, given:
        S: "barfoothefoobarman"
        L: ["foo", "bar"]

        You should return the indices: [0,9].
        (order does not matter).
 *
 *        Version:  1.0
 *        Created:  2013/8/22 22:32:27
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
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, int> dic;
        int len_per_word = L[0].size();
        int len = L.size() * len_per_word;
        for (vector<string>::iterator it = L.begin(); it != L.end(); it++) {
            if (dic.find(*it) != dic.end())
                dic[*it]++;
            else
                dic.insert(pair<string, int>(*it, 1));
        }
        vector<int> ret;
        if (S.size() < len)
            return ret;
        for (int i = 0; i <= (S.size() - len); i++) {
            if (is_valid(S.substr(i, len), len_per_word, L.size(), dic))
                ret.push_back(i);
        }
        return ret;
    }
    
    bool is_valid(string s, int len_per_word, int len, map<string, int>& dic) {
        map<string, int> st;
        for (int i = 0; i < len; i++) {
            string t = s.substr(i*len_per_word, len_per_word);
            if (st.find(t) != st.end())
                st[t]++;
            else
                st.insert(pair<string, int>(t, 1));
        }
        if (st.size() != dic.size())
            return false;
        for (map<string, int>::iterator it = st.begin(); it != st.end(); it++) {
            if (dic.find(it -> first) == dic.end())
                return false;
            if (it -> second != dic[it -> first])
                return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        sort(L.begin(), L.end());
        permuate_L(S, L, ret, 0);
        return ret;
    }
    void permuate_L(string &S, vector<string> &L, vector<int> &ret, int p) {
        int n = L.size();
        if (p == n) {
            findSubstringInOnePermutation(S, L, ret);
            return;
        }
        string last = L[p];
        for (int i = p; i < n; i++) {
            if ((i != p) && (L[i] == last))
                continue;
            last = L[i];
            swap(L[p], L[i]);
            permuate_L(S, L, ret, p+1);
            swap(L[p], L[i]);
        }
    }
    void findSubstringInOnePermutation(string &S, vector<string> &L, vector<int> &ret) {
        string p;
        for (vector<string>::iterator it = L.begin(); it != L.end(); it++)
            p += *it;
        int prefix_len = 0;
        std::size_t found = S.find(p);
        while (found != std::string::npos) {
            ret.push_back(prefix_len+found);
            prefix_len += (found + 1);
            found = (S.substr(prefix_len)).find(p);
        }
    }
};

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, int> dic;
        int len_per_word = L[0].size();
        int len = L.size() * len_per_word;
        for (vector<string>::iterator it = L.begin(); it != L.end(); it++) {
            if (dic.find(*it) != dic.end())
                dic[*it]++;
            else
                dic.insert(pair<string, int>(*it, 1));
        }
        vector<int> ret;
        if (S.size() < len)
            return ret;
        int n = S.size() - len;
        for (int i = 0; i <= n; i++) {
            string t = S.substr(i, len);
            if (is_valid(t, len_per_word, L.size(), dic))
                ret.push_back(i);
        }
        return ret;
    }
    
    bool is_valid(string &s, int len_per_word, int len, map<string, int> dic) {
        for (int i = 0; i < len; i++) {
            string t = s.substr(i*len_per_word, len_per_word);   
            if ((dic.find(t) == dic.end()) || (dic[t] == 0)) 
                return false;
            else {
                dic[t]--;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len_per_word = L[0].size();
        int len = L.size() * len_per_word;
        vector<int> ret;
        if (S.size() < len)
            return ret;
        map<string, int> dic;
        for (vector<string>::iterator it = L.begin(); it != L.end(); it++) {
            if (dic.find(*it) != dic.end())
                dic[*it]++;
            else
                dic.insert(pair<string, int>(*it, 1));
        }
        map<string, int> cur;
        int n = S.size() - len;
        for (int i = 0; i <= n; i++) {
            cur.clear();
            int j = 0;
            for (; j < L.size(); j++) {
                string t = S.substr(i+j*len_per_word, len_per_word);
                if (dic.find(t) == dic.end())
                    break;
                if (cur.find(t) == cur.end())
                    cur.insert(pair<string, int>(t, 1));
                else
                    cur[t]++;
                if (cur[t] > dic[t])
                    break;
            }
            if (j == L.size())
                ret.push_back(i);
        }
        return ret;
    }
};
