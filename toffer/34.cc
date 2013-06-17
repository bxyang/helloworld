/*
 * =====================================================================================
 *
 *       Filename:  34.cc
 *
 *    Description:  get ugly number
 *
 *        Version:  1.0
 *        Created:  06/17/2013 08:50:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cassert>

int min_among_three(int n1, int n2, int n3) {
    int min = (n1 < n2) ? n1 : n2;
    return (min < n3) ? min : n3;
}

// index >= 1
int get_ugly_number(const int index) {
    int* p_ugly_num = new int[index];
    p_ugly_num[0] = 1;
    int i = 1;
    int* p_multiply2 = p_ugly_num;
    int* p_multiply3 = p_ugly_num;
    int* p_multiply5 = p_ugly_num;
    while (i < index) {
        int last_ugly_num = p_ugly_num[i-1];
        while ( *p_multiply2 * 2 <= last_ugly_num)
            p_multiply2++;
        while ( *p_multiply3 * 3 <= last_ugly_num)
            p_multiply3++;
        while ( *p_multiply5 * 5 <= last_ugly_num)
            p_multiply5++;
        p_ugly_num[i++] = min_among_three(*p_multiply2 * 2, *p_multiply3 * 3, 
            *p_multiply5 * 5) ;
    }
    int ret = p_ugly_num[index-1];
    delete [] p_ugly_num;
    return ret;
}

int main() {
    for (int i = 1; i < 7; i++)
        assert(get_ugly_number(i) == i);
    assert(get_ugly_number(7) == 8);
    assert(get_ugly_number(8) == 9);
    assert(get_ugly_number(9) == 10);
    assert(get_ugly_number(10) == 12);
    assert(get_ugly_number(11) == 15);
    assert(get_ugly_number(1500) == 859963392);
    return 0;
}
