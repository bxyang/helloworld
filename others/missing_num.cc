/*
 * =====================================================================================
 *
 *       Filename:  missing_num.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/8 10:55:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<iostream>
#include<assert.h>
using namespace std;

int find_missing1num(int* data, int n) {
    assert((data != NULL) && (n>0));
    int m = 0;
    for (int i = 0; i < n; i++) {
        m ^= data[i];
        m ^= (i+1);
    }
    m ^= (n+1);
    return m;
}

void find_missing2num(int* data, int n, int& m1, int& m2) {
    assert((data != NULL) && (n>0));
    int m1_xor_m2 = 0;
    for (int i = 0; i < n; i++) {
        m1_xor_m2 ^= data[i];
        m1_xor_m2 ^= (i+1);
    }
    m1_xor_m2 ^= (n+1);
    m1_xor_m2 ^= (n+2);
    
    int k = m1_xor_m2 - (m1_xor_m2 & (m1_xor_m2 - 1));
    m1 = 0;
    m2 = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] & k)
            m1 ^= data[i];
        if ((i+1) & k)
            m1 ^= (i+1);
    }
    if ((n+1) & k)
        m1 ^= (n+1);
    if ((n+2) & k)
        m1 ^= (n+2);
    m2 = m1 ^ m1_xor_m2;
    swap(m1, m2);
}

int main() {
    int a[] = { 1,2,4,5,9,7,8,10,3 };  
    int b[] = { 1,2,4,5,9,7,6,11,3,10 };  
    int s1,s2;  
    int k = find_missing1num(a,sizeof(a)/sizeof(a[0]));  
    find_missing2num(b,sizeof(b)/sizeof(b[0]),s1,s2);  
    std::cout << "missing number 1 is " << k << std::endl;  
    std::cout << "missing number 2 is " << s1 << " and "<< s2 << std::endl;  
    return 0;
}
