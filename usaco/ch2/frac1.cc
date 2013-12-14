/*
ID: yangbao1
PROG: frac1
LANG: C++
*/


#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool num[161][161];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first+0.0)/p1.second < (p2.first+0.0)/p2.second;
}

bool is_reduced(int i, int j) {
    for (int k = 2; k <= i; k++)
        if ((i%k == 0) && (j%k == 0)) return false;
    return true;
}
int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w+", stdout); 
    
    int n;
    cin >> n;
    
    vector<pair<int, int> > nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(pair<int, int>(1, i));
   
    for (int i = 2; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (!is_reduced(i, j)) continue;
            nums.push_back(pair<int, int>(i, j));    
        }
    }
    sort(nums.begin(), nums.end(), cmp);
    cout << 0 << '/' << 1 << endl;
    for (vector<pair<int, int> >::iterator it = nums.begin(); 
        it != nums.end(); it++) {
        cout << it -> first << '/' << it -> second << endl;
    } 
    return 0;
}
