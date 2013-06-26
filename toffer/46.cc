/*
 * =====================================================================================
 *
 *       Filename:  46.cc
 *
 *    Description:  sum
 *
 *        Version:  1.0
 *        Created:  06/25/2013 02:21:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cassert>

class Temp {
 public:
    Temp(){
        kN++; 
        kSum += kN;
    }
    static void reset() {
        kN = 0;
        kSum = 0;
    }
    static int get_sum() {
        return kSum;
    }
 private:
    static int kN;
    static int kSum;
};

int Temp::kN = 0;
int Temp::kSum = 0;


int sum_sol1(int n) {
    Temp::reset();
    Temp* t = new Temp[n];
    int ret = Temp::get_sum();
    delete []t;
    return ret;
}

typedef unsigned int (*fun)(unsigned int);

unsigned int sol3_terminator(unsigned int n) {
    return 0;
}

unsigned int sum_sol3(unsigned int n) {
    static fun f[2] = {sol3_terminator, sum_sol3};
    return n + f[!(!n)](n-1);
}

int main() {
    assert(sum_sol1(5) == 15);
    assert(sum_sol3(5) == 15);
    return 0;
}
