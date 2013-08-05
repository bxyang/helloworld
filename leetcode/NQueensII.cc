/*
 * =====================================================================================
 *
 *       Filename:  NQueensII.cc
 *
 *    Description: 
        Follow up for N-Queens problem.

        Now, instead outputting board configurations, return the total number of distinct solutions.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/4 20:34:00
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
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        vector<set<int> > can_not_used(n);
        solveNQueens(can_not_used, 0, n, ret);
        return ret;
    }
   
    void solveNQueens(vector<set<int> > &can_not_used, int next, int n, int &ret) {
        if (next == (n-1)) {
            ret = ret + (n-can_not_used[n-1].size());
            return;
        }
        if (can_not_used[next].size() == n)
            return;
        vector<set<int> > old;
        for (int i = 0; i < n; i++) {
            if (can_not_used[next].find(i) == can_not_used[next].end() ) {
                old = can_not_used;
                if(! update(can_not_used, i, next, n)) {
                    can_not_used = old;
                    continue;
                }
                solveNQueens(can_not_used, next + 1, n, ret);
                can_not_used = old;
            }
        }
    }
    
    bool update(vector<set<int> > &can_not_used, int i, int next, int n) {
        int k = 1;
        for (int j = next + 1; j < n; j++) {
            can_not_used[j].insert(i);
            if (i-k >= 0)
                can_not_used[j].insert(i-k);
            if (i+k < n)
                can_not_used[j].insert(i+k);
            k++;
            if (can_not_used[j].size() == n)
                return false;
        }
        return true;
    }
};

class Solution {
    typedef vector<vector<bool> > vvbool;
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        vvbool can_not_used(n, vector<bool>(n, false));
        solveNQueens(can_not_used, 0, n, ret);
        return ret;
    }
   
    void solveNQueens(vvbool &can_not_used, int next, int n, int &ret) {
        if (next == n) {
            ret ++;
            return;
        }
        vvbool old;
        vector<bool> &tmp = can_not_used[next];
        for (int i = 0; i < n; i++) {
            if (! tmp[i]) {
                old.assign(can_not_used.begin() + next, can_not_used.end());
                update(can_not_used, i, next, n);
                solveNQueens(can_not_used, next + 1, n, ret);
                vvbool::iterator it_new = can_not_used.begin() + next;
                vvbool::iterator it_old = old.begin();
                for (; it_new != can_not_used.end(); it_new++, it_old++)
                    (*it_new) = (*it_old);
            }
        }
    }
    
    void update(vvbool &can_not_used, int i, int next, int n) {
        int k = 1;
        for (int j = next + 1; j < n; j++) {
            can_not_used[j][i] = true;;
            if (i-k >= 0)
                can_not_used[j][i-k] = true;
            if (i+k < n)
                can_not_used[j][i+k] = true;
            k++;
        }
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        vector<int> loc(n, -1);
        solveNQueens(loc, 0, n, ret);
        return ret;
    }
   
    void solveNQueens(vector<int> &loc, int next, int n, int &ret) {
        if (next == n) {
            ret ++;
            return;
        }
        for (int i = 0; i < n; i++) {
            loc[next] = i;
            if (is_valid(loc, next)) {
                solveNQueens(loc, next + 1, n, ret);
            }
        }
    }
    
    bool is_valid(vector<int> &loc, int next) {
        int key = loc[next];
        for (int i = 0; i < next; i++) {
            if ((loc[i] == key) || (abs(key-loc[i]) == (next - i)))
                return false;
        }
        return true;
    }
};

