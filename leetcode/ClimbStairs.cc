/*
 * =====================================================================================
 *
 *       Filename:  ClimbStairs.cc
 *
 *    Description: 
        You are climbing a stair case. It takes n steps to reach to the top.

        Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/30 17:09:44
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
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1)
            return 0;
        int a = 0;
        int b = 1;
        while (n > 0) {
            int t = b;
            b = b + a;
            a = t;
            n--;
        }
        return b;
    }
};

