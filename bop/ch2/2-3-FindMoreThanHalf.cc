/*
 * =====================================================================================
 *
 *       Filename:  2-3-FindMoreThanHalf.cc
 *
 *    Description:  find the number in array who makes up more than half of the array.
 *
 *        Version:  1.0
 *        Created:  06/27/2013 10:12:19 AM
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
#include<cassert>

int find(int* data, int n) {
    assert((data != NULL) && (n > 0));
    int candinate;
    int times = 0;
    for (int i = 0; i < n; i++) {
        if (times == 0) {
            candinate = data[i];
            times ++;
        } else { 
            if (candinate == data[i])
                times ++;
            else
                times --;
        }
    }
    return candinate;
}


int main() {
    return 0;
}
