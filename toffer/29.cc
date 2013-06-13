/*
 * =====================================================================================
 *
 *       Filename:  29.cc
 *
 *    Description:  find the number in an array 
 *                  who appear more than half of the array length
 *
 *        Version:  1.0
 *        Created:  06/13/2013 09:42:16 AM
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

int partion(int* array, int start, int end);

int find1(int* arr, int n) {
    assert((arr != NULL) && (n > 0));
    int ret = -1;
    int count = 0;
    int* q = arr + (n - 1);
    for (int* p = arr; p <= q; p++) {
        if (count == 0) {
            ret = *p;
            count = 1;
        } else {
            if (*p == ret)
                count++;
            else
                count--;
        } 
    }
    return ret;
}

int find2(int* arr, int n) {
    assert(n > 0);
    const int median = n / 2;
    int start = 0;
    int end = n - 1;
    while (start < end) {
        int i = partion(arr, start, end);
        if (i < median)
            start = i + 1;
        else if (i > median)
            end = i - 1;
        else
            break;
    }
    return arr[median];
}

int partion(int* array, int start, int end) {
    assert(start < end);
    int key = array[start];
    int mid = start;
    for (int j = start + 1; j <= end; j++) {
        if (array[j] < key) {
            int tmp = array[++mid];
            array[mid] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[mid];
    array[mid] = key;
    array[start] = tmp;
    return mid;
}



int main() {
    int a[9] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    assert(find1(a, 9) == 2);
    assert(find1(a, 1) == 1);
    assert(find2(a, 9) == 2);
    assert(find2(a, 1) == 1);

    return 0;
}
