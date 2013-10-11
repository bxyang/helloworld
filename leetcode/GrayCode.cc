/*
 * =====================================================================================
 *
 *       Filename:  GrayCode.cc
 *
 *    Description:  
        The gray code is a binary numeral system where two successive values differ in only one bit.

        Given a non-negative integer n representing the total number of bits in the code, 
        print the sequence of gray code. A gray code sequence must begin with 0.

        For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

        00 - 0
        01 - 1
        11 - 3
        10 - 2
        Note:
        For a given n, a gray code sequence is not uniquely defined.

        For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

        For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
  
 *
 *        Version:  1.0
 *        Created:  2013/7/23 14:09:48
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
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (n==0) {
            ret.push_back(0); // i don't think so, but leetcode think so
            return ret;
        }
        if (n==1) {
            ret.push_back(0);
            ret.push_back(1);
            return ret;
        }
        ret = grayCode(n-1);
        int len = ret.size();
        int add = 1 << n;
        for (int i = len - 1; i >= 0; i--)
            ret.push_back(ret[i]+add);
        return ret;
        
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (n==0) {
            ret.push_back(0); // i don't think so, but leetcode think so
            return ret;
        }
        int len = 1 << n;
        for (int i = 0; i < len; i++)
            ret.push_back(i^(i>>1));
        return ret;        
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(1<<n, 0);
        if (n == 0)
            return ret;
        ret[1] = 1;
        int len = 2;
        for (int i = 2; i <= n; i++) {
            for (int j = len - 1; j >= 0; j--)
                ret[len + (len - 1 - j)] = ret[j] | (1 << (i-1));
            len <<= 1;
        }
        return ret;
    }
};

