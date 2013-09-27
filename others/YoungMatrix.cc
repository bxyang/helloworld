/*
 * =====================================================================================
 *
 *       Filename:  YoungMatrix.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/26 11:07:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */



#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;


int* A;
int m;
int* B;
int n;
bool cmp(pair<int, int> left, pair<int, int> right) {
    return (A[left.first] + B[left.second]) > (A[right.first] + B[right.second]);  
}

int find_kth(int* A, int m, int* B, int n, int k) {
    if (m > n)
        return find_kth(B, n, A, m, k);
    vector<pair<int, int> > min_heap_v;
    for (int i = 0; i < m; i++)
        min_heap_v.push_back(pair<int, int>(i, 0));
    make_heap(min_heap_v.begin(), min_heap_v.end(), cmp);
    
    pair<int, int> t;
    while (k >= 1) {
         std::pop_heap (min_heap_v.begin(),min_heap_v.end(), cmp); 
         t = min_heap_v.back();
         min_heap_v.pop_back();
         if (t.second < n - 1) {
             min_heap_v.push_back(pair<int, int>(t.first, t.second+1));
             std::push_heap(min_heap_v.begin(), min_heap_v.end(), cmp);
         }
         k--;
    }
    return A[t.first] + B[t.second];
}

void find_kth_wrapper() {
    int m, n, k;
    while (scanf("%d %d %d\n", &m, &n, &k) != EOF) {
        A = new int[m];
        B = new int[n];
        for (int i = 0; i < m; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &B[i]);
        if (m > n) {
            int* t = A;
            A = B;
            B = t;
            swap(m, n);
        }
        int r = find_kth(A, m, B, n, k);
        printf("%d\n", r);
    }
}

int main() {
    find_kth_wrapper();
    return 0;
}
