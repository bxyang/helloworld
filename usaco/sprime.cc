/*
ID: yangbao1
PROG: sprime
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

bool isPrime(int n) {
    if (n == 1) return false;
    int sn = sqrt(n);
    for (int i = 2; i <= sn; i++)
        if (n%i == 0) return false;
    return true;     
}

int n;
int ten_pow[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w+", stdout);
    cin >> n;

    int start = ten_pow[n-1] * 2;
    int end = ten_pow[n];
    start +=1;
    while (start < end) {
        if (!isPrime(start)) { start += 2; continue; }
        int num_prefix = start;
        int i = 1;
        for (; i < n; i++) {
            num_prefix = num_prefix / 10;
            if (!isPrime(num_prefix)) {
                if ((num_prefix & 0x1 == 1) && (num_prefix != 1))
                    num_prefix += 2;
                else
                    num_prefix += 1;
                num_prefix *= ten_pow[i];   
                num_prefix += 1;
                start = num_prefix;
                break;
            }
        }
        if (i == n) {
            cout << start << endl;
            start += 2;
        }
    }
    return 0;
}
