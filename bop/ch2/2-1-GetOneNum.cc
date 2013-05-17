/*
 * =====================================================================================
 *
 *       Filename:  GetOneNum.cc
 *
 *    Description:  given a number, return the number of "1" if converted to binary
 *
 *        Version:  1.0
 *        Created:  05/17/2013 10:34:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict 
 *
 * =====================================================================================
 */

#include<assert.h>
int method1(unsigned int a);
int method2(unsigned int a);
int method3(unsigned int a);

int main(int argc, char* argv[]){
    assert(method1(1)==1);
    assert(method2(1)==1);
    assert(method3(1)==1);
    assert(method1(21)==3);
    assert(method2(21)==3);
    assert(method3(21)==3);
    assert(method1(20)==2);
    assert(method2(20)==2);
    assert(method3(20)==2);
    return 0;
}

int method1(unsigned int a){
    int num = 0;
    while(a){
        num += (a % 2 == 1);
        a = a>>1;
    }
    return num;
}

int method2(unsigned int a){
    int num = 0;
    while(a){
        num += (a & 0x01);
        a = a>>1;
    }
    return num;
}

int method3(unsigned int a){
    int num = 0;
    while(a){
        a &= (a - 1);
        num++;
    }
    return num;
}
