/*
ID: yangbao1
PROG: checker
LANG: C++
*/

#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int sol[13];
int sol_num = 0;
int printed_sol_num = 0;

void solve(int next) {
    if (next == n) {
        sol_num ++;
        if (printed_sol_num == 3) return;
        printed_sol_num++;
        cout << sol[0];
        for (int i = 1; i < n; i++)
            cout << " " << sol[i];
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        int j = 0;
        for (; j < next; j++) {
            int t = abs(sol[j] - i);
            if ( (t == 0) || (t == (next - j)) ) break;
        }
        if (j == next) {
            sol[next] = i;
            solve(next + 1); 
        }
    }
}

int main() {
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w+", stdout);
    cin >> n;
    if (n != 13) 
        solve(0);
    else {
        int last_num = 0;
        for (int i = 1; i <= 6; i++) {
            sol[0] = i;
            last_num = sol_num;
            solve(1);
            sol_num = sol_num - last_num + sol_num;
        }
        sol[0] = 7;
        solve(1);
    }
    cout << sol_num << endl;
    return 0;
}
