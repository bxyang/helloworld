/*
 * =====================================================================================
 *
 *       Filename:  SubsetsII.cc
 *
 *    Description:  
        Given a collection of integers that might contain duplicates, S, return all possible subsets.

        Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        For example,
        If S = [1,2,2], a solution is:

        [
          [2],
          [1],
          [1,2,2],
          [2,2],
          [1,2],
          []
        ]
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/1 18:35:03
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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        return subsetsWithDup(S, 0);
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S, int pos) {
        vector<vector<int> > ret;
        if (pos == S.size())
            return ret;
        int key = S[pos];
        int i = pos + 1;
        for (; i < S.size(); i++) {
            if (S[i] != key)
                break;
        }
        i = i - pos;
        vector<vector<int> > prefix;
        for (int j = 0; j <= i; j++)
            prefix.push_back(vector<int>(j, S[pos]));
        vector<vector<int> > tmp = subsetsWithDup(S, pos+i);
        if (tmp.size() == 0) {
            return prefix;
        }
        for (vector<vector<int> >::iterator it = tmp.begin(); it != tmp.end(); it++) {
            for (vector<vector<int> >::iterator prefix_it = prefix.begin(); 
                prefix_it != prefix.end(); prefix_it++) {
                vector<int> item = (*prefix_it);    
                item.insert(item.end(), (*it).begin(), (*it).end());
                ret.push_back(item);
            }
        }
        return ret;
    }
};
