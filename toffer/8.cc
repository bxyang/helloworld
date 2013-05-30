/*
 * =====================================================================================
 *
 *       Filename:  8.cc
 *
 *    Description:  find min in rotated array which was ordered ascendly
 *
 *        Version:  1.0
 *        Created:  05/30/2013 04:54:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */
#include<cassert>

int search_min(int* p, int n) {
    int left = 0;
    int right = n - 2;
    while (left < right) {
        int mid = (left + right) / 2;
        if (p[mid] > p[n-1])
            left = mid + 1;
        else {
            right = mid;
        }
    }
    return left;
}


int main() {
    int a[7] = {6, 7, 8, 1, 2, 3, 4};
    assert(search_min(a, 7) == 3);
    assert(search_min(a, 3) == 0);
    assert(search_min(a+3, 3) == 0);
    assert(search_min(a+2, 3) == 1);
    return 0;
}
