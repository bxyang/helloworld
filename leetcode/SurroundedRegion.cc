/*
 * =====================================================================================
 *
 *       Filename:  SurroundedRegion.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/8 11:27:56
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
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // 0 unknown
        // 1 -ing
        // 2 surrounded 
        // 3 not surrounded
        // 0 w 3 e; 1 n 2 s
        int row_num = board.size();
        if (row_num == 0)
            return;
        int col_num = board[0].size();
        vector<vector<vector<int> > > region_color(row_num,
            vector<vector<int> >(col_num, vector<int>(4, 0)));
        vector<pair<int, int> > reverse_region;
        for (int r = 0; r < row_num; r++) {
            for (int c = 0; c < col_num; c++) {
                if (board[r][c] == 'X')
                    continue;
                int ret = search(board, row_num, col_num, r, c, region_color);
                if (ret == 2)
                    reverse_region.push_back(pair<int, int>(r, c));
            }
        }
        for(vector<pair<int, int> >::iterator it = reverse_region.begin(); it != reverse_region.end(); it++) {
            board[it -> first][it -> second] = 'X';        
        }
    }
    
    int search(vector<vector<char> > &board, int row_num, int col_num, 
        int r, int c, vector<vector<vector<int> > > &region_color) {
        if (board[r][c] == 'X')
            return 2;
        vector<int>& color = region_color[r][c];
        for (int i = 0; i < 4; i++) {
            if (color[i] == 1)
                return 2;
        }
        for (int i = 0; i < 4; i++) {
            if ((color[i] == 2) || (color[i] == 3))
                continue;
            if (color[i] == 1) {
                color[i] = 2;
                continue;
            }
            switch(i) {
            case 0:
                if (c == 0)
                    color[i] = 3;
                else {
                    color[i] = 1;
                    color[i] = search(board, row_num, col_num, r, c-1, region_color);
                }
                break;
            case 3:
                if (c == (col_num - 1))
                    color[i] = 3;
                else {
                    color[i] = 1;
                    color[i] = search(board, row_num, col_num, r, c+1, region_color);
                }
                break;
            case 1:
                if (r == 0)
                    color[i] = 3;
                else {
                    color[i] = 1;
                    color[i] = search(board, row_num, col_num, r - 1, c, region_color);
                }
                break;                    
            case 2:
                if (r == (row_num - 1))
                    color[i] = 3;
                else {
                    color[i] = 1;
                    color[i] = search(board, row_num, col_num, r + 1, c, region_color);
                }
                break;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (color[i] == 3)
                return 3;
        }
        return 2;        
    }
};








class Solution {
public:
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row_num = board.size();
        if (row_num == 0)
            return;
        int col_num = board[0].size();
        if (col_num == 0)
            return;
        for (int i = 0; i < col_num; i++)
            bfs(board, row_num, col_num, 0, i);
        for (int i = 0; i < col_num; i++)
            bfs(board, row_num, col_num, row_num - 1, i);
        for (int i = 1; i < (row_num - 1); i++)
            bfs(board, row_num, col_num, i, 0);
        for (int i = 1; i < (row_num - 1); i++)
            bfs(board, row_num, col_num, i, col_num - 1);
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                if (board[i][j] == '+')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    
    void bfs(vector<vector<char> > &board, int row_num, int col_num, int r, int c) {
        if (! is_valid(board, row_num, col_num, r, c))
            return;
        queue<pair<int, int> > q;
        q.push(pair<int, int>(r, c));
        while (!(q.empty())) {
            pair<int, int> p = q.front();
            r = p.first;
            c = p.second;
            board[r][c] = '+';
            q.pop();
            if (is_valid(board, row_num, col_num, r, c-1))
                q.push(pair<int, int>(r, c-1));
            if (is_valid(board, row_num, col_num, r, c+1))
                q.push(pair<int, int>(r, c+1));                
            if (is_valid(board, row_num, col_num, r-1, c))
                q.push(pair<int, int>(r-1, c));
            if (is_valid(board, row_num, col_num, r+1, c))
                q.push(pair<int, int>(r+1, c));            
        }
    }
    
    bool is_valid(vector<vector<char> > &board, int row_num, int col_num, int r, int c) {
        if ((r >= 0) && (r < row_num) && (c >= 0) && (c < col_num) && (board[r][c] == 'O'))
            return true;
        return false;
    }
};



class Solution {
public:
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row_num = board.size();
        if (row_num == 0)
            return;
        int col_num = board[0].size();
        if (col_num == 0)
            return;
        for (int i = 0; i < col_num; i++) {
            if (board[0][i] == 'O')
                bfs(board, row_num, col_num, 0, i);
            if (board[row_num - 1][i] == 'O')
                bfs(board, row_num, col_num, row_num - 1, i);
        }
        for (int i = 1; i < (row_num - 1); i++) {
            if (board[i][0] == 'O')
                bfs(board, row_num, col_num, i, 0);
            if (board[i][col_num - 1] == 'O')
                bfs(board, row_num, col_num, i, col_num - 1);
        }
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                if (board[i][j] == '+')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    
    void bfs(vector<vector<char> > &board, int row_num, int col_num, int r, int c) {
        queue<pair<int, int> > q;
        q.push(pair<int, int>(r, c));
        board[r][c] = '+';
        while (!(q.empty())) {
            pair<int, int> p = q.front();
            r = p.first;
            c = p.second;
            q.pop();
            if (((c-1) >= 0) && (board[r][c-1] == 'O')) {
                q.push(pair<int, int>(r, c-1));
                board[r][c-1] = '+';
            }
            if (((c+1) < col_num) && (board[r][c+1] == 'O')) {
                q.push(pair<int, int>(r, c+1));
                board[r][c+1] = '+';
            }
            if (((r-1) >= 0) && (board[r-1][c] == 'O')) {
                q.push(pair<int, int>(r-1, c));
                board[r-1][c] = '+';
            }
            if (((r+1) < row_num) && (board[r+1][c] == 'O')) {
                q.push(pair<int, int>(r+1, c));            
                board[r+1][c] = '+';
            }
        }
    }
};



