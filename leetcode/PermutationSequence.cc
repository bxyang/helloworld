/*
 * =====================================================================================
 *
 *       Filename:  PermutationSequence.cc
 *
 *    Description:  
        The set [1,2,3,бн,n] contains a total of n! unique permutations.

        By listing and labeling all of the permutations in order,
        We get the following sequence (ie, for n = 3):

        "123"
        "132"
        "213"
        "231"
        "312"
        "321"
        Given n and k, return the kth permutation sequence.

    Note: Given n will be between 1 and 9 inclusive.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/2 16:47:08
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
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret(n, '1');
        for (int i = 1; i < n; i++)
            ret[i] = i + 1 + '0';
        getPermutation(ret, k, 0, n);
        return ret;
    }
    
    void getPermutation(string &num, int k, int p, int n) {
        if (p == n)
            return;
        int f = factorial(n-p-1);
        int t = f;
        int i = 0;
        while (k > f){
            f += t;
            i++;
        }
        swap(num[p], num[p+i]);
        shift_right(num, p+1, p+i);
        k = k - f + t;
        getPermutation(num, k, p+1, n);
    }
    
    int factorial(int n) {
        int ret = 1;
        for (int i = 1; i <= n; i++)
            ret *= i;
        return ret;
    }
    
    void shift_right(string &num, int p1, int p2){
        if (p1 >= p2)
            return;
        char c = num[p2];
        for (int i = p2; i > p1; i--)
            num[i] = num[i-1];
        num[p1] = c;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret(n, '1');
        for (int i = 1; i < n; i++)
            ret[i] = i + 1 + '0';
        getPermutation(ret, k, n);
        return ret;
    }
    
    void getPermutation(string& num, int k, int n) {
        if (k <= 1)
            return;
        int f = 1;
        int i = 1;
        for (; i <= n; i++) {
            f = f*i;
            if (k <= f)
                break;
        }
        
        int p = n - i;
        f = f/i;
        int t = f;
        i = 0;
        while (k > f) {
            f += t;
            i++;
        }
        swap(num[p], num[p+i]);
        shift_right(num, p+1, p+i);
        k = k - f + t;
        getPermutation(num, k, n);
    }
    
    void shift_right(string &num, int p1, int p2){
        if (p1 >= p2)
            return;
        char c = num[p2];
        for (int i = p2; i > p1; i--)
            num[i] = num[i-1];
        num[p1] = c;
    }
};


// this solution seems more slowly
class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret(n, '1');
        for (int i = 1; i < n; i++)
            ret[i] = i + 1 + '0';
        int* fac = new int[n];
        int f = 1;
        for (int i = 1; i <= n; i++) {
            f *= i;
            fac[i-1] = f;
            
        }
        getPermutation(ret, k, n, fac);
        return ret;
    }
    
    void getPermutation(string& num, int k, int n, int *fac) {
        if (k <= 1)
            return;
        int f = 1;
        int i = 1;
        for (; i <= n; i++) {
            f = fac[i-1];
            if (k <= f)
                break;
        }
        
        int p = n - i;
        f = f/i;
        int t = f;
        i = 0;
        while (k > f) {
            f += t;
            i++;
        }
        swap(num[p], num[p+i]);
        shift_right(num, p+1, p+i);
        k = k - f + t;
        getPermutation(num, k, n, fac);
    }
    
    void shift_right(string &num, int p1, int p2){
        if (p1 >= p2)
            return;
        char c = num[p2];
        for (int i = p2; i > p1; i--)
            num[i] = num[i-1];
        num[p1] = c;
    }
};

