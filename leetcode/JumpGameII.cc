/*
 * =====================================================================================
 *
 *       Filename:  JumpGameII.cc
 *
 *    Description:  
        Given an array of non-negative integers, you are initially positioned at the first index of the array.

        Each element in the array represents your maximum jump length at that position.

        Your goal is to reach the last index in the minimum number of jumps.

        For example:
        Given array A = [2,3,1,1,4]

        The minimum number of jumps to reach the last index is 2. 
        (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/6 11:26:27
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
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (n == 1)
            return 0;
        vector<int> min_jump(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            if ((n-1-i) <= A[i])
                min_jump[i] = 1;
            else {
                int min = 0x7ffffffe;
                for (int j = 1; j <= A[i]; j++) {
                    if (min_jump[i+j] < min)
                        min = min_jump[i+j];
                }
                min_jump[i] = min + 1 ;
            }
        }
        return min_jump[0];
    }
};
