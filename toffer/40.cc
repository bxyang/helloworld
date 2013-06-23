/*
 * =====================================================================================
 *
 *       Filename:  40.cc
 *
 *    Description:  find the two single number
 *
 *        Version:  1.0
 *        Created:  06/23/2013 08:08:13 PM
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
#include<utility>

int find_single_number(int* data, int length) {
    assert((data != NULL) && (length > 0));
    int ret = data[0];
    for (int i = 1; i < length; i++)
        ret ^= data[i];
    return ret;
}

int divide_to_two_group(int* data, int length) {
    assert((data != NULL) && (length > 1));
    int ret = data[0];
    for (int i = 1; i < length; i++)
        ret ^= data[i];
    int bit_num = sizeof(int) - 1;
    int x = 0x01;
    int i = 0;
    for (; i < bit_num; i++) {
        if (ret & x == 1)
            break;
        x <<= 1;
    }
    assert(i != bit_num);
    int left = 0;
    int right = length - 1;
    while (left < right) {
        if (((data[left]) & x) == 0)
            left++;
        else if (((data[right]) & x) != 0)
            right--;
        else {
            std::swap(data[left], data[right]);
            left++;
            right--;
        }
    }
    assert (left < length);
    if ((data[left] & x )== 0)
        return left;
    else
        return (left - 1);
}

void find_two_single_number(int* data, int length, int& n1, int& n2) {
    int mid = divide_to_two_group(data, length);
    n1 = find_single_number(data, mid + 1);
    n2 = find_single_number(data + mid + 1, length - mid - 1);
}
int main() {
    int data[8] = {1, 2, 3, 3, 2, 1, 6, 5};
    int n1;
    int n2;
    find_two_single_number(data, 8, n1, n2);
    printf("%d %d\n", n1, n2);
}
