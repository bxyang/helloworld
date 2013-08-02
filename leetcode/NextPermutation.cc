/*
 * =====================================================================================
 *
 *       Filename:  NextPermutation.cc
 *
 *    Description:  
        Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

        If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

        The replacement must be in-place, do not allocate extra memory.

        Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
        1,2,3 ¡ú 1,3,2
        3,2,1 ¡ú 1,2,3
        1,1,5 ¡ú 1,5,1
        
        solution: find the longest reverse order suffix, 
        swap the previous one and the one in suffix which is larger than the previous but is least in suffix, 
        and then sort the suffix
        suppose  a1, a2, a3, ..... ak,  ai...ak is the longest reverse order suffix, st, ai > ..> ak, but ai-1 < ai.
        swap ai-1 and the aj, aj > ai-1, but aj+1...ak < ai-1, then sort ai....ak   
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/2 15:43:37
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
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        int i = len-2;
        for (; i >= 0; i--) {
            if (num[i] < num[i+1])
                break;
        }
        
        int ph = i;
        int p1 = ph + 1;
        int p2 = len - 1;
        if (ph != -1) {
            i = len - 1;
            for (; i > ph; i--) {
                if (num[i] > num[ph])
                    break;
            }
            swap(num[ph], num[i]);
        }
        
        while (p1 < p2) {
            swap(num[p1], num[p2]);
            p1++;
            p2--;
        }
    }
};
