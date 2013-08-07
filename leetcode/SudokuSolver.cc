/*
 * =====================================================================================
 *
 *       Filename:  SudokuSolver.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/8/6 15:28:34
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
    typedef vector<vector<char> > vvchar;
    typedef vector<vector<bool> > vvbool;
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vvbool row_sets(9, vector<bool>(9, false));
        vvbool col_sets(9, vector<bool>(9, false));
        vvbool box_sets(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                row_sets[i][c-'1'] = true;
                col_sets[j][c-'1'] = true;
                box_sets[i/3*3 + j/3][c-'1'] = true;
            }
        }
        solveSudoku(board, row_sets, col_sets, box_sets, 0, 0);
    }
    
    bool solveSudoku(vvchar &board, vvbool &row_sets, 
        vvbool &col_sets, vvbool &box_sets, 
        int row, int col) {
        if (row == 9)
            return true;
        int next_row;
        int next_col;
        if (col < 8) {
            next_col = col + 1;
            next_row = row;
        } else {
            if (row < 8) {
                next_col = 0;
                next_row = row + 1;
            } else {
                next_row = 9;
                next_col = 0;
            }  
        }
        
        if (board[row][col] != '.')
            return solveSudoku(board, row_sets, col_sets, box_sets, next_row, next_col);
        
        for (int i = 0; i < 9; i++) {
            if (row_sets[row][i] || col_sets[col][i] || box_sets[row/3*3 + col/3][i])
                continue;
            row_sets[row][i] = true;
            col_sets[col][i] = true;
            box_sets[row/3*3 + col/3][i] = true;
            board[row][col] = i + '1';
            if (solveSudoku(board, row_sets, col_sets, box_sets, next_row, next_col))
                return true;
            row_sets[row][i] = false;
            col_sets[col][i] = false;
            box_sets[row/3*3 + col/3][i] = false;
        }
        board[row][col] = '.';
        return false;
    }
};
