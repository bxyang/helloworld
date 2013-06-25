/*
 * =====================================================================================
 *
 *       Filename:  45.cc
 *
 *    Description:  joseph circle
 *
 *        Version:  1.0
 *        Created:  06/25/2013 11:07:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */



int joseph_circle(int n, int m) {
    if ((n < 1) || (m < 1))
        return -1;
    int last = 0;
    for (int i = 2; i <= n; i++)
        last = (last + m) % n;
    return last;
}

int joseph_circle_list(int n, int m) {
    if ((n < 1) || (m < 1))
        return -1;
    list<int> numbers;
    for (int i = 0; i < n; i++) {
        numbers.push_back(i);
    }
    list<int>::iterator cur = numbers.begin();
    while (numbers.size() > 1) {
        for (int i = 1; i < m; i++) {
            cur ++;
            if (cur == numbers.end())
                cur = numbers.begin();
        }
        list<int>::iterator next = (++cur);
        if (next == numbers.end())
            next = numbers.begin();
        --cur;
        numbers.erase(cur);
        cur = next;
    }
    return *(cur);
}



int main() {
    return 0;
}
