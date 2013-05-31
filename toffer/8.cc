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
        else if (p[mid] < p[n-1])
            right = mid;
        else {
            int ret = n-1;
            for (int i = mid - 1; i > -1; i--) {
                if (p[i] > p[ret])
                    break;
                else if (p[i] < p[ret])
                    ret = i;
            }
            if (ret != (n-1))
                return ret;
            for (int i = mid + 1; i <= right; i++) {
                if(p[ret] > p[i])
                    ret = i;
            }
            return ret;
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
    int b[5] = {1, 1, 1, 0, 1};
    assert(search_min(b, 5) == 3);
    assert(search_min(b+1, 4) == 2);
    int c[5] = {4, 2, 1, 0, 1};
    assert(search_min(b, 5) == 3);
    int d[5] = {1, 1, 1, 1, 1};
    assert(-1< search_min(b, 5) < 5);
    return 0;
}
