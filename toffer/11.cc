/*
 * =====================================================================================
 *
 *       Filename:  11.cc
 *
 *    Description:  power(a, b)
 *
 *        Version:  1.0
 *        Created:  05/31/2013 04:31:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cmath>
#include<cassert>
#include<stdexcept>
#include<cstdio>

const double EPS = 0.0000001;

double my_pow(double a, int b) {
    if((a < EPS) && (a > -EPS)) {
        if(b==0)
            return 0;
        else
            return 1;
    }
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    if(b < 0) {
        double ret = my_pow(a, -b);
        if (ret < EPS)
            throw std::runtime_error("");
        return 1 / ret;
    } else {
        double ret = my_pow(a, b >> 1);
        ret = ret * ret;
        if (b & 0x1 == 1) {
            ret = ret * a;
        }
        return ret;
    }
}

int main() {
    double ret = my_pow(3.5, 5);
    assert(std::abs(pow(3.5, 5) - my_pow(3.5, 5)) < EPS);
    return 0;
}
