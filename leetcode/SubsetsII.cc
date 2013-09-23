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
        vector<int> item;
        vector<vector<int> > result;
        subsetsWithDupCore(result, S, item, 0);
        return result;
    }
    
    void subsetsWithDupCore(vector<vector<int> > &result, vector<int> &S,
        vector<int> &item, int next) {
        result.push_back(item);
        for (int i = next; i < S.size(); i++) {
            if ((i != next) && (S[i] == S[i-1]))
                continue;
            item.push_back(S[i]);
            subsetsWithDupCore(result, S, item, i+1);
            item.pop_back();
        }
    }
}; 
 
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        result.push_back(vector<int>());
        subsetsWithDupCore(result, S, S.size() - 1);
        return result;
    }
    
    void subsetsWithDupCore(vector<vector<int> > &result, vector<int> &S, int next) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (next < 0)
            return;
        int i = next - 1;
        for (; i >= 0; i--) {
            if (S[i] != S[next])
                break;
        }
        
        int count = ( (next != 0) ? (next - i) : 1);
        subsetsWithDupCore(result, S, next - count);
        int result_len = result.size();
        for (int j = 0; j < count; j++) {
            int start = j*result_len;
            int end = start + result_len;
            for (int k = start; k < end; k++) {
                result.push_back(result[k]);
                result.back().push_back(S[next]);
            }
        }
    }
};
 
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
