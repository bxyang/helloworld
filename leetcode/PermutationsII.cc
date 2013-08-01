/*
 * =====================================================================================
 *
 *       Filename:  PermutationsII.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/8/1 19:09:02
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
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        permuteUnique(num, 0, ret);
        return ret;
    }
    
    void permuteUnique(vector<int> &num, int pos, vector<vector<int> > &ret) {
        if (pos == num.size()) {
            ret.push_back(num);
            return;
        }
        permuteUnique(num, pos+1, ret);
        for (int i = pos+1; i < num.size(); i++) {
            if ((num[i] == num[pos]) || (num[i] == num[i-1]))
                continue;
            swap(num[i], num[pos]);
            permuteUnique(num, pos + 1, ret);
            swap(num[i], num[pos]);
        }        
    }
};

