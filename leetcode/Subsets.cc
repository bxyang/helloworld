/*
 * =====================================================================================
 *
 *       Filename:  Subsets.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/2 11:09:19
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
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        return subsetsCore(S, S.rbegin());
    }
    
    vector<vector<int> > subsetsCore(vector<int>& S, vector<int>::reverse_iterator it) {
        vector<vector<int> > sub_ret(1);
        if (it == S.rend())
            return sub_ret;
        int e = *it;
        it++;
        sub_ret = subsetsCore(S, it);
        int len = sub_ret.size();
        for (int i = 0; i < len; i++) {
            vector<int> tmp = sub_ret[i];
            tmp.push_back(e);
            sub_ret.push_back(tmp);
        }
    }
};


class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > ret(1);
        int n = S.size();
        for (int i = 0; i < n; i++) {
            int m = ret.size();
            for (int j = 0; j < m; j++) {
                vector<int> t = ret[j];
                t.push_back(S[i]);
                ret.push_back(t);
            }
        }
        return ret;
    }
};
