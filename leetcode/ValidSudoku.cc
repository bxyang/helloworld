/*
 * =====================================================================================
 *
 *       Filename:  ValidSudoku.cc
 *
 *    Description:  
        Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

        The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/6 11:55:41
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
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < 9; i++) {
            vector<bool> flags(9, false);
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                if(flags[c-'1'])
                    return false;
                flags[c-'1'] = true;
            }       
        }
        
        for (int i = 0; i < 9; i++) {
            vector<bool> flags(9, false);
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c == '.')
                    continue;
                if(flags[c-'1'])
                    return false;
                flags[c-'1'] = true;
            }       
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<bool> flags(9, false);
                for (int k = 3*i; k < 3*(i+1); k++) {
                    for (int l = 3*j; l < 3*(j+1); l++) {
                        char c = board[k][l];
                        if (c == '.')
                            continue;
                        if(flags[c-'1'])
                            return false;
                        flags[c-'1'] = true;
                    }
                }
            }
        }
        return true;
    }
};

