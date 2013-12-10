/*
ID: yangbao1
PROG: pprime
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
    int sn = sqrt(n);
    for (int i = 2; i <= sn; i++)
        if (n%i == 0) return false;
    return true;     
}
int a, b;

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w+", stdout);
    cin >> a >> b;
    
    for (int i = 5; i < 10; i+=2) {
        if (i < a) continue;
        if (i > b) break;
        if (isPrime(i)) cout << i << endl;
    }

    for (int d1 = 1; d1 < 10; d1 += 2) {
        int t = d1 + 10 * d1;
        if (t < a) continue;
        if (t > b) break;
        if (isPrime(t)) cout << t << endl;
    }
    
    for (int d1 = 1; d1 < 10; d1 += 2) {
        for (int d2 = 0; d2 < 10; d2++) {
            int t = d1 + 10*d2 + 100*d1;
            if (t < a) continue;
            if (t > b) break;
            if (isPrime(t)) cout << t << endl;
        }
    }

    for (int d1 = 1; d1 < 10; d1 += 2) {
        for (int d2 = 0; d2 < 10; d2++) {
            int t = 110*d2 + 1001*d1;
            if (t < a) continue;
            if (t > b) break;
            if (isPrime(t)) cout << t << endl;
        }
    }
    
    for (int d1 = 1; d1 < 10; d1 += 2) {
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                int t = 100*d3 + 1010*d2 + 10001*d1;
                if (t < a) continue;
                if (t > b) break;
                if (isPrime(t)) cout << t << endl;
            }
        }
    }
    for (int d1 = 1; d1 < 10; d1 += 2) {
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                int t = 1100*d3 + 10010*d2 + 100001*d1;
                if (t < a) continue;
                if (t > b) break;
                if (isPrime(t)) cout << t << endl;
            }
        }
    }


    for (int d1 = 1; d1 < 10; d1 += 2) {
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                for (int d4 = 0; d4 < 10; d4++) {
                    int t = 1000*d4 + 10100*d3 + 100010*d2 + 1000001*d1;
                    if (t < a) continue;
                    if (t > b) break;
                    if (isPrime(t)) cout << t << endl;
                }
            }
        }
    }
 
    for (int d1 = 1; d1 < 10; d1 += 2) {
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                for (int d4 = 0; d4 < 10; d4++) {
                    int t = 11000*d4 + 100100*d3 + 1000010*d2 + 10000001*d1;
                    if (t < a) continue;
                    if (t > b) break;
                    if (isPrime(t)) cout << t << endl;
                }
            }
        }
    }   
    return 0;
}
