/*
 * =====================================================================================
 *
 *       Filename:  24.cc
 *
 *    Description:  verifying the post tranversing sequence of binary search tree
 *
 *        Version:  1.0
 *        Created:  06/08/2013 02:24:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cassert>
#include<cstdlib>

bool verify_bst_post_seq(int* p, int start, int end) {
    if ((p == NULL) || (start > end))
        return false;
    if (start == end)
        return true;
    int k = p[end];
    int mid = start;
    for (; (mid < end) && (k > p[mid]); mid++);
    for (int i = mid + 1; i < end; i++){
        if (p[i] < k)
            return false;
    }
    bool lc = true;
    bool rc = true;
    if (mid - 1 > start)
        lc = verify_bst_post_seq(p, start, mid - 1);
    if (mid < end)
        rc = verify_bst_post_seq(p, mid, end - 1);
    return lc && rc;
}

int main() {
    int a[] = {5, 7, 6, 9, 11, 10, 8};
    assert(verify_bst_post_seq(a, 0, 6));
    int b[] = {7, 4, 6, 5};
    assert(!verify_bst_post_seq(b, 0, 3));
    return 0;
}
