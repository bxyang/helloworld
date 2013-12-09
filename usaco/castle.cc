/*
ID: yangbao1
PROG: castle
LANG: C++
*/


#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;


int m, n;
unsigned int floor_plan[50][50];
unsigned short int flags[50][50];

int dfs(int r, int c, unsigned short int cluster) {
    if (flags[r][c]) return 0;
    flags[r][c] = cluster;
    int cnt = 1;
    int t = floor_plan[r][c];
    if ( ((t & 0x1) == 0) && (c > 0)) 
        cnt += dfs(r, c-1, cluster);
    if ( ((t & 0x2) == 0) && (r > 0)) 
        cnt += dfs(r-1, c, cluster);
    if ( ((t & 0x4) == 0) && (c+1 < n))
        cnt += dfs(r, c+1, cluster);
    if ( ((t & 0x8) == 0) && (r+1 < m))
        cnt += dfs(r+1, c, cluster);
    return cnt;
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w+", stdout);   
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> floor_plan[i][j];
    }
    
    memset(flags, 0, sizeof(flags));
    unsigned short int room_num = 0;
    int largest_size = 0;
    vector<int> room_size(1, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (flags[i][j]) continue;
            ++room_num;
            int s = dfs(i, j, room_num);
            room_size.push_back(s);
            largest_size = (s > largest_size ? s : largest_size);
        }
    }
    
    int largest_size_removed = largest_size;
    int r = 0;
    int c = 0;
    char direction;
    for (int j = 0; j < n; j++) {
        for (int i = m-1; i >= 0; i--) {
            int t = floor_plan[i][j];
            if ( ((t & 0x2) != 0) && (i > 0) && (flags[i][j] != flags[i-1][j])) {
                int new_size = room_size[flags[i][j]];
                new_size += room_size[flags[i-1][j]];
                if (new_size <= largest_size_removed) continue;
                r = i;
                c = j;
                largest_size_removed = new_size;
                direction = 'N'; 
            }
            
            if ( ((t & 0x4) != 0) && (j < (n-1)) && (flags[i][j] != flags[i][j+1])) {
                int new_size = room_size[flags[i][j]];
                new_size += room_size[flags[i][j+1]];
                if (new_size <= largest_size_removed) continue;
                r = i;
                c = j;
                largest_size_removed = new_size;
                direction = 'E'; 
            }
        }
    }
    r++;
    c++;
    cout << room_num << endl;
    cout << largest_size << endl;
    cout << largest_size_removed << endl;
    cout << r << " " << c << " " << direction <<endl;
    return 0;
}
