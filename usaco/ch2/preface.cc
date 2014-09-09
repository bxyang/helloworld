/*
ID: yangbao1
PROG: preface
LANG: C++
*/

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


using namespace std;

uint32_t roman_show[3501][7];
// I -> 0
// V -> 1
// X -> 2
// L -> 3
// C -> 4
// D -> 5
// M -> 6

//roman_show[1] = {1, 0, 0, 0, 0, 0, 0};
//roman_show[4] = {1, 1, 0, 0, 0, 0, 0};
//roman_show[5] = {0, 1, 0, 0, 0, 0, 0};
//roman_show[9] = {1, 0, 1, 0, 0, 0, 0};
//roman_show[10] = {0, 0, 1, 0, 0, 0, 0};
//roman_show[40] = {0, 0, 1, 1, 0, 0, 0};
//roman_show[50] = {0, 0, 0, 1, 0, 0, 0};
//roman_show[90] = {0, 0, 1, 0, 1, 0, 0};
//roman_show[100] = {0, 0, 0, 0, 1, 0, 0};
//roman_show[400] = {0, 0, 0, 0, 1, 1, 0};
//roman_show[500] = {0, 0, 0, 0, 0, 1, 0};
//roman_show[900] = {0, 0, 0, 0, 1, 0, 1};
//roman_show[1000] = {0, 0, 0, 0, 0, 0, 1};

uint32_t interval_idx[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

uint64_t sum_roman[7] = {1, 0, 0, 0, 0, 0, 0};

int main() {
    memset(&roman_show[0][0], 0, sizeof(roman_show));
    roman_show[1][0] = 1;
    roman_show[4][0] = 1;
    roman_show[4][1] = 1;
    roman_show[5][1] = 1;
    roman_show[9][0] = 1;
    roman_show[9][2] = 1;
    roman_show[10][2] = 1;
    roman_show[40][2] = 1;
    roman_show[40][3] = 1;
    roman_show[50][3] = 1;
    roman_show[90][2] = 1;
    roman_show[90][4] = 1;
    roman_show[100][4] = 1;
    roman_show[400][4] = 1;
    roman_show[400][5] = 1;
    roman_show[500][5] = 1;
    roman_show[900][4] = 1;
    roman_show[900][6] = 1;
    roman_show[1000][6] = 1;


    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w+", stdout);
    int N;
    cin >> N;

    int p = 0;
    for (int i = 2; i <= N; i++) {
        if (i == interval_idx[p+1]) {
            for (int j = 0; j < 7; j++) sum_roman[j] += roman_show[interval_idx[p+1]][j];
            p ++;
        }
        else {
            for (int j = 0; j < 7; j++) {
                roman_show[i][j] = roman_show[interval_idx[p]][j] + roman_show[i-interval_idx[p]][j];
                sum_roman[j] += roman_show[i][j];
            }
        }
    }

    if (sum_roman[0] != 0) cout << "I " << sum_roman[0] << endl;
    if (sum_roman[1] != 0) cout << "V " << sum_roman[1] << endl;
    if (sum_roman[2] != 0) cout << "X " << sum_roman[2] << endl;
    if (sum_roman[3] != 0) cout << "L " << sum_roman[3] << endl;
    if (sum_roman[4] != 0) cout << "C " << sum_roman[4] << endl;
    if (sum_roman[5] != 0) cout << "D " << sum_roman[5] << endl;
    if (sum_roman[6] != 0) cout << "M " << sum_roman[6] << endl;
}
