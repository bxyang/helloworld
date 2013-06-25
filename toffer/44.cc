/*
 * =====================================================================================
 *
 *       Filename:  44.cc
 *
 *    Description:  poker straight
 *
 *        Version:  1.0
 *        Created:  06/25/2013 10:10:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdlib>
#include<cassert>
#include<string.h>

int compare(const void* a, const void* b) {
    return (*((int*)a) - *((int*)b));
}

bool is_poker_straight(int* numbers, int n) {
    if ((numbers == NULL) || (n < 1))
        return false;
    if (n==1)
        return true;
    int* cpy_nums = new int[n];
    memcpy(cpy_nums, numbers, sizeof(int)*n);
    qsort(cpy_nums, n, sizeof(int), compare);
    int i = 0;
    for (; i < n; i++) {
        if (cpy_nums[i] != 0)
            break;
    }
    if (i == n)
        return false;
    int zero_num = i;
    int space = 0;
    for (; i < (n-1); i++) {
        space += (cpy_nums[i+1] - cpy_nums[i] - 1);
    }
    delete []cpy_nums;
    if (space > zero_num)
        return false;
    else
        return true;
}

int main() {
    int num[6] = {1, 0, 3, 4, 5, 7};
    assert(is_poker_straight(num, 5));
    assert(is_poker_straight(num+1, 4));
    assert(!is_poker_straight(num+2, 4));
    assert(is_poker_straight(num, 4));
    assert(is_poker_straight(num+1, 4));
    assert(!is_poker_straight(num, 6));
    assert(!is_poker_straight(num+2, 4));
    return 0;
}
