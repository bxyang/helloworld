/*
 * =====================================================================================
 *
 *       Filename:  MedianofTwoSortedArrays.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/8/17 22:47:08
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
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = m + n;
        bool is_odd = false;
        if (a&0x1 == 1)
            is_odd = true;
        int mid = a/2;
        int start_a = 0;
        int end_a = m - 1;
        int start_b = 0;
        int end_b = n - 1;
        
        while ( (start_a <= end_a) && (start_b <= end_b) ) {
            int bmid = start_b + (end_b - start_b + 1)/2;
            int first_ge = bi_search(A, start_a, end_a, B[bmid]);
            int lnum = 0;
            if (first_ge == -1) {
                lnum = end_b - bmid;
                if ((end_a - start_a + 1) + (bmid - start_b) >= mid)
                    end_b = bmid;
                else
                {
                    mid -= ((end_a - start_a + 1) + (bmid - start_b));
                    start_a = end_a + 1;
                    start_b = bmid;
                }
            } else {
                lnum = bmid - start_b + first_ge - start_a;
                if (lnum == mid) {
                    if (is_odd)
                        return B[bmid];
                    else {
                        if (first_ge == start_a)
                            return (B[bmid] + B[bmid-1])/2.0;
                        else if (bmid == start_b)
                            return (B[bmid] + A[first_ge-1])/2.0;
                        else {
                            return (B[bmid] + 
                                        (B[bmid-1] > A[first_ge-1] ? B[bmid-1] : A[first_ge-1])
                                    )/2.0;
                        }
                    }
                } else if (lnum > mid) {
                    end_a = first_ge - 1;
                    end_b = bmid - 1;
                } else {
                    start_a = first_ge;
                    start_b = bmid;
                    mid -= lnum;
                }
            }
            if (lnum == 0) {
                if (first_ge == -1) {                    
                    if ((end_a - start_a + 1 + end_b - start_b) == mid) {
                        if (is_odd)
                            return B[end_b];
                        else{
                            if (start_b == end_b)
                                return (A[end_a] + B[start_b])/2.0;
                            else
                                return ((B[start_b] > A[end_a] ? B[start_b] : A[end_a]) + B[end_b])/2.0;
                        }
                    }
                    else
                        end_b -= 1;
                } else {
                    if (mid == 1)
                        return is_odd ? A[start_a] : (A[start_a] + B[start_b])/2.0;
                    start_b += 1;
                    mid -= 1;
                }
            }        
        }
        
        if (start_a > end_a) {
            return is_odd ? B[start_b+mid] : (B[start_b+mid] + B[start_b+mid-1])/2.0; 
        } else {
            return is_odd ? A[start_a+mid] : (A[start_a+mid] + A[start_a+mid-1])/2.0;
        }
    }
    
    int bi_search(int data[], int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left)/2;
            int key = data[mid];
            if (key >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if (data[right] < target)
            return -1;
        else
            return right;
    }
};


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = m + n;
        if (l & 0x1 == 1)
            return find_kth_number(A, m, B, n, l/2+1);
        else
            return (find_kth_number(A, m, B, n, l/2) + find_kth_number(A, m, B, n, l/2 + 1))/2.0;
    }
    
    int find_kth_number(int *a, int m, int *b, int n, int k) {
        if (m > n)
            return find_kth_number(b, n, a, m, k);
        if (m == 0)
            return b[k-1];
        if (k == 1)
            return a[0] < b[0] ? a[0] : b[0];
        int pa = min(m, k/2);
        int pb = k - pa;
        if (a[pa-1] < b[pb-1])
            return find_kth_number(a+pa, m-pa, b, pb+1, k - pa);
        else
            return find_kth_number(a, pa+1, b+pb, n-pb, k-pb);
    }
};


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = m + n;
        if (l & 0x1 == 1)
            return find_kth_number(A, m, B, n, l/2+1);
        else
            return (find_kth_number(A, m, B, n, l/2) + find_kth_number(A, m, B, n, l/2 + 1))/2.0;
    }
    
    int find_kth_number(int *a, int m, int *b, int n, int k) {
        if (m > n)
            return find_kth_number(b, n, a, m, k);
        if (m == 0)
            return b[k-1];
        if (k == 1)
            return a[0] < b[0] ? a[0] : b[0];
        int target = b[n/2];
        int first_ge = bi_search(a, m, target);
        if (first_ge != -1) {
            int l = first_ge + n/2;
            if (l == (k-1))
                return b[n/2];
            else if (l > (k-1))
                return find_kth_number(a, first_ge, b, n/2, k);
            else {
                if (l != 0)
                    return find_kth_number(a+first_ge, m - first_ge, b+n/2, n-n/2, k-l);
                else
                    return a[k-2];
            }
        } else {
            int l = m + n/2;
            if (l >= k)
                return find_kth_number(a, m, b, n/2, k);
            else
                return *(b+n/2+k-l-1);
        }
    }
    
    
    int bi_search(int* a, int n, int target) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left)/2;
            int key = a[mid];
            if (key >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if (a[right] >= target)
            return right;
        else
            return -1;
    }
};

