/*
 * =====================================================================================
 *
 *       Filename:  Sqrt.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/1 13:31:48
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
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = x;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long mid2 = mid * mid;
            if (mid2 == x)
                return mid;
            else if (mid2 > x)
                right = mid;
            else {
                left = mid;
                if ((right - left) == 1) {
                    if (right * right == x)
                        return right;
                    else
                        return left;
                }
            }
        }
        return left;
    }
};

