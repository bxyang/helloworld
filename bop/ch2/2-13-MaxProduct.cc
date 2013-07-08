/*
 * =====================================================================================
 *
 *       Filename:  2-13-MaxProduct.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/2013 09:32:33 PM
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



int max_product(int* data, int n) {
    assert((data != NULL) && (n > 0));
    int zero_counts = 0;
    int positive_counts = 0;
    int negtive_counts = 0;
    int min_positive = 0;
    int max_negtive = 0;   
    for (int i = 0; i < n; i++) {
        if (data[i] == 0) {
            zero_counts ++;
            continue;
        }
        if (data[i] > 0) {
            positive_counts ++;
            min_positive = (min_positive == 0) ? data[i] : (
                (min_positive > data[i]) ? data[i] : min_positive);
            continue;
        } 
        if (data[i] < 0) {
            negtive_counts ++;
            max_negtive = (max_negtive == 0) ? data[i] : (
                (max_negtive < data[i]) ? data[i] : max_negtive);
        } 
    }
    if (zero_counts >= 2)
        return 0;
    int key;
    if (zero_counts == 1) {
        if (negtive_counts & 0x1 == 1)
            return 0;
        else
            key = 0;
    } else {
        if (negtive_counts & 0x1 == 1)
            key = max_negtive;
        else
            key = min_positive;
    }
    int ret = 1;
    for (int i = 0; i < n; i++)
        ret *= ((data[i] == key) ? 1:data[i]);
    return ret;
}


int main() {
    return 0;
}
