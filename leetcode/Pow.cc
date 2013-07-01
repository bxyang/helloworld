/*
 * =====================================================================================
 *
 *       Filename:  Pow.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/1 11:31:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) {
            return 1;
        }
        bool is_negtive = false;
        if (n < 0) {
            is_negtive = true;
            n = 0 - n;
        }
        if (n == 1)
            return is_negtive ? 1/x : x;
        double t = pow(x, n/2);
        if (n % 2 == 0) {
            t *= t;
        } else {
            t *= t;
            t *= x;
        }
        return is_negtive ? 1/t :t;
    }
};

