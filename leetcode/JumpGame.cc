/*
 * =====================================================================================
 *
 *       Filename:  JumpGame.cc
 *
 *    Description:  
        Given an array of non-negative integers, you are initially positioned at the first index of the array.

        Each element in the array represents your maximum jump length at that position.

        Determine if you are able to reach the last index.

        For example:
        A = [2,3,1,1,4], return true.

        A = [3,2,1,0,4], return false.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/5 11:21:32
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
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1)
            return false;
        vector<int> can_reach(n, -1);
        can_reach[n-1] = 1;
        return canJump(A, 0, n, can_reach);
    }
    
    bool canJump(int A[], int next, int n, vector<int> &can_reach) {
        if (can_reach[next] != -1)
            return can_reach[next];
        int max_step = A[next];
        bool ret = false;
        int step = n-next-1;
        if (step <= max_step)
            ret = true;
        else {
            for (int i = 1; i <= max_step; i++) {
                if (i > step)
                    break;
                if (canJump(A, next + i, n, can_reach)) {
                    ret = true;
                    break;
                }
            }
        }
        can_reach[next] = ret;
        return ret;
    }
};

// greedy

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return false;            
        int step = A[0];        
        for(int i = 1; i < n; i++) {
            if (step > 0) {
                step--;
                step = max(step, A[i]);
            }
            else
                return false;
        }                
        return true;
    }
};

// great explaination http://www.mysjtu.com/page/M0/S884/884146.html 
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int step = A[0];
        for (int i = 1; i < n; i++) {
            if (step <= 0)
                return false;
            step--;
            if (A[i] > step)
                step = A[i];
        }
        return true;
    }
};

