/*
 * =====================================================================================
 *
 *       Filename:  WordSearch.cc
 *
 *    Description:
        Given a 2D board and a word, find if the word exists in the grid.

        The word can be constructed from letters of sequentially adjacent cell, 
        where "adjacent" cells are those horizontally or vertically neighboring. 
        The same letter cell may not be used more than once.

        For example,
        Given board =

        [
          ["ABCE"],
          ["SFCS"],
          ["ADEE"]
        ]
        word = "ABCCED", -> returns true,
        word = "SEE", -> returns true,
        word = "ABCB", -> returns false.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/30 16:06:57
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
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = board.size();
        if (m == 0)
            return false;
        int n = board[0].size();
        int l = word.length();
        if (l==0)
            return false;
                
        vector<vector<bool> > state = vector<vector<bool> >(m, vector<bool>(n ,false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, state, word, 0, i, j))
                    return true;
            }
        }
        return false;
        
    }
    
    bool exist(vector<vector<char> > &board, vector<vector<bool> > &state,
        string word, int li, int mi, int ni){
        if ((mi < 0) || (mi >= board.size()) || (ni < 0) || (ni >= board[0].size()))
            return false;
        if (state[mi][ni])
            return false;
        if (board[mi][ni] != word[li])
            return false;
        li++;
        if (li == word.length())
            return true;
        state[mi][ni] = true;
        bool ret = false;
        ret = (ret || exist(board, state, word, li, mi, ni - 1));
        ret = (ret || exist(board, state, word, li, mi, ni + 1));
        ret = (ret || exist(board, state, word, li, mi - 1, ni));
        ret = (ret || exist(board, state, word, li, mi + 1, ni));
        state[mi][ni] = false;
        return ret;
    }
};
