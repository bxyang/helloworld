/*
 * =====================================================================================
 *
 *       Filename:  38.cc
 *
 *    Description:  the number of given number in ordered array
 *
 *        Version:  1.0
 *        Created:  06/18/2013 09:31:49 PM
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


int get_first_k(int* data, int n, int k) {
    assert((data != NULL) && (n > 0));
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (k > data[mid])
            left = mid + 1;
        else if (k < data[mid])
            right = mid - 1;
        else
            right = mid;
    }
    if (data[left] == k)
        return left;
    else
        return -1;
}

int get_last_k(int* data, int n, int k) {
    assert((data != NULL) && (n > 0));
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (k > data[mid])
            left = mid + 1;
        else if (k < data[mid])
            right = mid - 1;
        else {
            if (left == mid) {
                if (data[right] == k)
                    return right;
                else
                    return left;
            }
            else
                left = mid;
        }
    }
    if (data[left] == k)
        return left;
    else
        return -1;
}

int get_number_of_k(int* data, int n, int k) {
    if ((data == NULL) || (n < 1))
        return 0;
    int left = get_first_k(data, n, k);
    if (left == -1)
        return 0;
    int right = get_last_k(data, n, k);
    return right - left + 1;
}
int main() {
    int data[8] = {1, 2, 3, 3, 3, 3, 4, 5};
    assert(get_number_of_k(data, 8, 1) == 1);
    assert(get_number_of_k(data, 8, 2) == 1);
    assert(get_number_of_k(data, 8, 3) == 4);
    assert(get_number_of_k(data, 8, 4) == 1);
    assert(get_number_of_k(data, 8, 5) == 1);
    assert(get_number_of_k(data + 3, 5, 3) == 3);

    return 0;
}
