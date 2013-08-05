/*
 * =====================================================================================
 *
 *       Filename:  Anagrams.cc
 *
 *    Description:  
        Given an array of strings, return all groups of strings that are anagrams.

        Note: All inputs will be in lower-case.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/5 12:09:03
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
    typedef vector<vector<int> >  vv_int;
    typedef vector<vector<int> >::iterator  vv_int_iter;
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if (strs.size() == 0)
            return ret;
        vector<bool> avail(strs.size(), true);
        vector<vector<int> > tables(strs.size(), vector<int>(26, 0));
        set_hash_table(tables, strs);
        
        for (int i = 0; i < strs.size(); i++) {
            if (! avail[i])
                continue;
            int old_size = ret.size();
            string orig = strs[i];
            vector<int> &orig_table = tables[i];
            for (int j = i + 1; j < strs.size(); j++) {
                if (! avail[i])
                    continue;
                if (orig.length() != strs[j].length())
                    continue;
                if (is_same(orig_table, tables[j])) {
                    ret.push_back(strs[j]);
                    avail[j] = false;
                }
            }
            if (old_size != ret.size()) {
                ret.push_back(strs[i]);
                avail[i] = false;
            }
        }
        return ret;
    }
    
    void set_hash_table(vv_int &tables, vector<string> &strs) {
        vv_int_iter p_table = tables.begin();
        vector<string>::iterator p_strs = strs.begin();
        for (; p_table != tables.end(); p_table++, p_strs++) {
            for (string::iterator it = p_strs -> begin(); it != p_strs -> end(); it++)
                (*p_table)[*it - 'a']++;  
        }
    }
    
    bool is_same(vector<int> &table1, vector<int> &table2) {
        vector<int>::iterator it1 = table1.begin();
        vector<int>::iterator it2 = table2.begin();
        for (; it1 != table1.end(); it1++, it2 ++){
            if (*(it1) != *(it2))
                return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, int> dic;
        int i = 0;
        vector<string> ret;
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++, i++) {
            string key = (*it);
            sort(key.begin(), key.end());
            if (dic.find(key) == dic.end()) {
                dic.insert(pair<string, int>(key, i));
            } else {
                int p = dic[key];
                if (p != -1) {
                    ret.push_back(strs[p]);
                    dic[key] = -1;
                }
                ret.push_back(*it);
            }
        }
        return ret;
    }
};
