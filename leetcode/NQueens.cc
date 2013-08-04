/*
 * =====================================================================================
 *
 *       Filename:  NQueens.cc
 *
 *    Description: 
        The n-queens puzzle is the problem of placing n queens on an n?n chessboard such that no two queens attack each other.



        Given an integer n, return all distinct solutions to the n-queens puzzle.

        Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

        For example,
        There exist two distinct solutions to the 4-queens puzzle:

        [
         [".Q..",  // Solution 1
          "...Q",
          "Q...",
          "..Q."],

         ["..Q.",  // Solution 2
          "Q...",
          "...Q",
          ".Q.."]
        ]
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/4 17:29:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict  
 *
 * =====================================================================================
 */

class Solution {
    typedef vector<vector<string> > vvstr;
    
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vvstr ret;
        vector<set<int> > can_not_used(n);
        vector<string> sol = vector<string>(n, string(n, '.'));
        solveNQueens(can_not_used, sol, 0, n, ret);
        return ret;
    }
    
    void solveNQueens(vector<set<int> > &can_not_used, vector<string> &sol, int next, int n, vvstr &ret) {
        if (next == n) {
            ret.push_back(sol);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (can_not_used[next].find(i) == can_not_used[next].end() ) {
                vector<set<int> > old = can_not_used;
                update(can_not_used, i, next, n);
                sol[next][i] = 'Q';
                solveNQueens(can_not_used, sol, next + 1, n, ret);
                sol[next][i] = '.';
                can_not_used = old;
            }
        }
    }
    
    void update(vector<set<int> > &can_not_used, int i, int next, int n) {
        for (int j = next + 1; j < n; j++) {
            can_not_used[j].insert(i);
        }
        int k = 1;
        for (int j = next + 1; j < n; j++) {
            if (i-k >= 0)
                can_not_used[j].insert(i-k);
            else
                break;
            k++;
        }
        k = 1;
        for (int j = next + 1; j < n; j++) {
            if (i+k < n)
                can_not_used[j].insert(i+k);
            else
                break;
            k++;
        }
    }
};
