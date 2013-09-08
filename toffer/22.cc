/*
 * =====================================================================================
 *
 *       Filename:  22.cc
 *
 *    Description:  given the sequence of pushing a stack, judge whether the sequence of
 *                  poping is valid
 *
 *        Version:  1.0
 *        Created:  06/06/2013 03:05:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<stack>
#include<cassert>
#include<cstdlib>

bool is_valid_poping(const int* push_array, const int* pop_array, int n) {
    assert((push_array != NULL) && (pop_array != NULL) && n > 0);
    int push_i = 0;
    int pop_i = 0;
    std::stack<int> helper;
    while ((pop_i < n)) {
        if ((!helper.empty()) && (helper.top() == pop_array[pop_i])) {
            helper.pop();
        } else {
            while (push_i < n) {
                helper.push(push_array[push_i]);
                if (push_array[push_i] == pop_array[pop_i]) {
                    push_i++;
                    break;
                } else
                    push_i++;
            }
            if (helper.top() == pop_array[pop_i])
                helper.pop();
            else
                return false;
        }
        pop_i ++;
    }
    return true;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b1[] = {4, 5, 3, 2, 1};
    int b2[] = {4, 3, 5, 1, 2};
    assert(is_valid_poping(a, b1, 5));
    assert(!is_valid_poping(a, b2, 5));
    assert(is_valid_poping(a, b1 + 3, 2));
    assert(is_valid_poping(a, b2 + 3, 2));
    assert(!is_valid_poping(a, b1 + 2, 2));
    assert(is_valid_poping(a, b1 + 4, 1));
}
