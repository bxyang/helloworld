/*
 * =====================================================================================
 *
 *       Filename:  SortColors.cc
 *
 *    Description:  
        Given an array with n objects colored red, white or blue, sort them so that 
        objects of the same color are adjacent, with the colors in the order red, white and blue.

        Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

        Note:
        You are not suppose to use the library's sort function for this problem.

        Follow up:
        A rather straight forward solution is a two-pass algorithm using counting sort.
        First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with 
        total number of 0's, then 1's and followed by 2's.

        Could you come up with an one-pass algorithm using only constant space?
 
 *
 *        Version:  1.0
 *        Created:  2013/7/25 18:42:30
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
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p0 = 0;
        while (A[p0] == 0)
            p0++;
        int p2 = n - 1;
        while (A[p2] == 2)
            p2--;
        int i = p0;
        while (i <= p2) {
            if (A[i] == 1) {
                i++;
                continue;
            }
            else if (A[i] == 0) {
                swap(A[i++], A[p0++]);
            } else {
                swap(A[i], A[p2--]);
            }
        }
    }
};


class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int p1 = n - 1;
        int p2 = n - 1;
        
        while ((i <= p1) && (i <= p2)) {
            if (A[i] == 0) {
                i++;
            } else if (A[i] == 2) {
                swap(A[i], A[p2]);
                p2 --;
            } else {
                if (p1 < p2) {
                    swap(A[i], A[p1]);
                    p1 --;
                } else {
                    swap(A[i], A[p2]);
                    p1 = p2 - 1;
                }
            }
        }
    }
};

