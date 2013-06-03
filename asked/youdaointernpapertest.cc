/*
 * =====================================================================================
 *
 *       Filename:  youdaointernpapertest.cc
 *
 *    Description:  modified binary search
 *                  return the least number which is great or equal than given key 
 *                  in a ascend array 
 *
 *        Version:  1.0
 *        Created:  06/03/2013 09:00:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cassert>
#include<cstdlib>

int bi_search_great(const int* data, int n, int key) {
    if ((data == NULL) || n < 1)
        return -1;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = (left + right)/2;
        if (data[mid] < key)
            left = mid + 1;
        else
            right = mid;
    }
    if (key <= data[left])
        return left;
    else
        return -1;
}


int main() {
    int data[] = {0, 1, 1, 1, 1, 2, 4};
    assert(bi_search_great(data, 1, 0) == 0);
    assert(bi_search_great(data, 1, 1) == -1);
    assert(bi_search_great(data, 2, 0) == 0);
    assert(bi_search_great(data, 2, 1) == 1);
    assert(bi_search_great(data, 7, 1) == 1);
    assert(bi_search_great(data, 7, 2) == 5);
    assert(bi_search_great(data, 7, 3) == 6);
    assert(bi_search_great(data, 7, 4) == 6);
    return 0;
}
