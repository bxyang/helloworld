/*
 * =====================================================================================
 *
 *       Filename:  DivideTwoIntegers.cc
 *
 *    Description:  
        Divide two integers without using multiplication, division and mod operator.
 *
 *        Version:  1.0
 *        Created:  2013/8/9 10:51:19
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
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long t_dividend = abs((long long)dividend);
        long long t_divisor = abs((long long)divisor);
        int ret = 0;
        while (t_dividend >= t_divisor) {
            long long divi_part = t_divisor;
            int t = 1;
            while (t_dividend >= divi_part) {
                t_dividend -= divi_part;
                divi_part <<= 1;
                ret += t;
                t <<= 1;
            }
        }
        
        return ((dividend^divisor)>> 31) ? (-ret) : ret;
    }
};
