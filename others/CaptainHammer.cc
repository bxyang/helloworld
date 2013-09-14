/*
 * =====================================================================================
 *
 *       Filename:  CaptainHammer.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/14 13:50:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<list>
#include<iterator>
#include<map>
#include<vector>
#include<queue>
using namespace std;

#define PI 3.14159265

int main() {
    FILE* fin = fopen("B-small-attempt0.in", "r");
    FILE* fout = fopen("B-small-attempt0.out", "w");
    int n;
    fscanf(fin, "%d\n", &n);
    for (int i = 1; i <= n; i++) {
        int v;
        int d;
        fscanf(fin, "%d %d\n", &v, &d);
        double s = d*9.8/v/v;
        double result = asin (s) * 180.0 / PI/2;
        fprintf(fout, "Case #%d: %.7f\n", i, result);
    }
    return 0;
}
