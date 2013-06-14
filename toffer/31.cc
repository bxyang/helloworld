/*
 * =====================================================================================
 *
 *       Filename:  31.cc
 *
 *    Description:  sub array who has max sum
 *
 *        Version:  1.0
 *        Created:  06/13/2013 03:26:40 PM
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


int find_sub_array(int* arr, int n, int& start, int& end) {
    assert((arr != NULL) && (n > 0));
    int max_sum = arr[0];
    start = 0;
    end = 0;
    int cur_sum = 0;
    int cur_start = 0;
    int cur_end = 0;
    for (int i = 0; i < n; i++) {
        if (cur_sum <= 0) {
            cur_sum = arr[i];
            cur_start = i;
        }
        else {
            cur_sum += arr[i];
        }
        cur_end = i;
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
            start = cur_start;
            end = cur_end;
        }
    }
    return max_sum;
}
int main() {
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int start = -1;
    int end = -1;
    assert(find_sub_array(data, 8, start, end) == 18);
    assert(start == 2);
    assert(end == 6);
    return 0;
}
