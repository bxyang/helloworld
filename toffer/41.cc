/*
 * =====================================================================================
 *
 *       Filename:  41.cc
 *
 *    Description:  find the two number which sums up to given number
 *
 *        Version:  1.0
 *        Created:  06/23/2013 09:23:32 PM
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

void find_two_numbers(int* data, int length, int k) {
    assert((data != NULL) && (length > 1));
    int left = 0;
    int right = length - 1;
    while (left < right) {
        int t = data[left] + data[right];
        if (t == k) {
            printf("%d+%d=%d\n", data[left], data[right], k);
            break;
        }
        else if (t > k)
            right--;
        else
            left++;
    }
}

void find_consecutive_numbers(int* data, int length, int k) {
    assert((data != NULL) && (length > 0));
    int left = 0;
    int right = 0;
    int sum = data[0];
    while(right < length) {
        if (sum < k) {
            right++;
            sum += data[right];
        }
        else if(sum > k) {
            if (left == right) {
                right++;
                left++;
                sum = data[left];
            }
            else {
                sum -= data[left];
                left++;
            }
        } else {
            for (int i = left; i <= right; i++) {
                printf("%d ", data[i]);
            }
            printf("\n");
            sum -= data[left];
            left++;
        }
    }
}

int main() {
    int data[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    find_two_numbers(data, 9, 7);
    find_consecutive_numbers(data, 9, 15);
}
