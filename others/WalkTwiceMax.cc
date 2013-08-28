/*
 * =====================================================================================
 *
 *       Filename:  WalkTwiceMax.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/2013 07:39:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<vector>
#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

typedef vector<pair<int, int> > v_p_int;

const int N = 5;

void walk(int grid[][N], v_p_int& path1, int& sum1, int next1, 
    v_p_int& path2, int& sum2, int next2, int n, int& max_sum) {
    
    if (next1 == (2*n - 2)) {
        if (next2 == (2*n - 2)) {
            int t = sum1 + sum2; 
            max_sum = max_sum > t ? max_sum : t;
            return;
        }
        
        pair<int, int> last_pos = path2[next2-1];
        pair<int, int> path1_next_pos = path1[next2];
        if (last_pos.first == (n-1)) {
            last_pos.second++;
            if (path1_next_pos == last_pos)
                return;
            sum2 += grid[last_pos.first][last_pos.second];
            path2[next2] = last_pos;
            walk(grid, path1, sum1, next1, path2, sum2, next2+1, n, max_sum);
            sum2 -= grid[last_pos.first][last_pos.second];
        } else if (last_pos.second == (n-1)) {
            last_pos.first++;
            if (path1_next_pos == last_pos)
                return;
            sum2 += grid[last_pos.first][last_pos.second];
            path2[next2] = last_pos;
            walk(grid, path1, sum1, next1, path2, sum2, next2+1, n, max_sum);
            sum2 -= grid[last_pos.first][last_pos.second];
        } else {
            last_pos.first++;
            if (path1_next_pos != last_pos) {
                sum2 += grid[last_pos.first][last_pos.second];
                path2[next2] = last_pos;
                walk(grid, path1, sum1, next1, path2, sum2, next2+1, n, max_sum);
                sum2 -= grid[last_pos.first][last_pos.second];
            }
            
            last_pos.first--;
            
            last_pos.second++;
            if (path1_next_pos != last_pos) {
                sum2 += grid[last_pos.first][last_pos.second];
                path2[next2] = last_pos;
                walk(grid, path1, sum1, next1, path2, sum2, next2+1, n, max_sum);
                sum2 -= grid[last_pos.first][last_pos.second];
            }
        }
        return;
    }

    pair<int, int> last_pos = path1[next1-1];
    if (last_pos.first == (n-1)) {
        last_pos.second++;
        sum1 += grid[last_pos.first][last_pos.second];
        path1[next1] = last_pos;
        walk(grid, path1, sum1, next1+1, path2, sum2, next2, n, max_sum);
        sum1 -= grid[last_pos.first][last_pos.second];
    } else if (last_pos.second == (n-1)) {
        last_pos.first++;
        sum1 += grid[last_pos.first][last_pos.second];
        path1[next1] = last_pos;
        walk(grid, path1, sum1, next1+1, path2, sum2, next2, n, max_sum);
        sum1 -= grid[last_pos.first][last_pos.second];
    } else {
        last_pos.first++;
        sum1 += grid[last_pos.first][last_pos.second];
        path1[next1] = last_pos;
        walk(grid, path1, sum1, next1+1, path2, sum2, next2, n, max_sum);
        sum1 -= grid[last_pos.first][last_pos.second];
    
        last_pos.first--;
        
        last_pos.second++;
        sum1 += grid[last_pos.first][last_pos.second];
        path1[next1] = last_pos;
        walk(grid, path1, sum1, next1+1, path2, sum2, next2, n, max_sum);
        sum1 -= grid[last_pos.first][last_pos.second];
    }
}

int walk_dp(int grid[N][N]) {
    int state[2*N-1][N][N];
    state[2*N-2][N-1][N-2] = 0;
    for (int i = 2*N - 3; i >= 1; i--) {
        int xmin = i-(N-1) > 0 ? (i-(N-1)) : 0;
        int xmax = i < (N-1) ? i : (N-1);
        for (int p1 = xmax; p1 >= xmin; p1--) {
            for (int p2 = xmax; p2 > p1; p2--) {
                // state[i][p1][p2]
                // state[i+1][p1+1][p2+1]       // r r
                // state[i+1][p1+1][p2]      // r d
                // state[i+1][p1][p2+1]       // d r
                // state[i+1][p1][p2]       // d d
                if (p1 == p2)
                    continue;
                int max_sum = 0;
                if (((p1+1) < N) && ((p2+1) < N))
                    max_sum = state[i+1][p1+1][p2+1];
                if (((p1+1) < N) && ((i+1-p2) < N) && (p1+1 != p2))
                    max_sum = max_sum > state[i+1][p1+1][p2] ? max_sum : state[i+1][p1+1][p2];
                if (((p2+1) < N) && ((i+1-p1) < N) && (p2+1 != p1))
                    max_sum = max_sum > state[i+1][p1][p2+1] ? max_sum : state[i+1][p1][p2+1];
                if (((i+1-p1) < N) && ((i+1-p2) < N))
                    max_sum = max_sum > state[i+1][p1][p2] ? max_sum : state[i+1][p1][p2];
                
                state[i][p1][p2] = max_sum + grid[p1][i-p1] + grid[p2][i-p2];
            }
        }
    }
    return state[1][0][1] + grid[0][0] + grid[N-1][N-1];
}

int main() {
    int max_sum = 0;
    int grid[5][5]={  
    {2,0,8,0,2},  
    {0,0,0,0,0},  
    {0,3,2,0,0},  
    {0,10,0,0,0},  
    {2,0,8,0,2}};
    v_p_int path1(9, pair<int, int>(0, 0));
    v_p_int path2 = path1;
    int sum1 = 0;
    int sum2 = 0;
    walk(grid, path1, sum1, 1, path2, sum2, 1, 5, max_sum);
    cout << max_sum + grid[0][0] + grid[4][4] << endl;
    
    cout << walk_dp(grid) << endl;
    
    return 0;
}
