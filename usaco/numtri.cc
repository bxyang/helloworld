/*
ID: yangbao1
PROG: numtri
LANG: C++
*/

#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w+", stdout);
    int row_num;
    cin >> row_num;
    vector<vector<int> > tri_mat;
    for (int i = 1; i <= row_num; i++) {
        tri_mat.push_back(vector<int>(i,0));
        int k = i - 1;
        for (int j = 0; j < i; j++)
            cin >> tri_mat[k][j];   
    }

    bool flag = 0;
    vector<vector<int> > dp(2, vector<int>(row_num, 0));
    dp[flag] = tri_mat[row_num - 1];
    for (int i = row_num - 2; i >= 0; i--) {
        flag = (!flag); 
        for (int j = 0; j <= i; j++)
            dp[flag][j] = max(dp[!flag][j], dp[!flag][j+1]) + tri_mat[i][j];
    }
    cout << dp[flag][0] << endl;
    
    return 0;
}
