/*
 * =====================================================================================
 *
 *       Filename:  SuffixArray.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/15 17:34:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


const int N = 128;

void double_alg(char data[], int n, int rank[], int sa[]) {
    int counts[N];
    for (int i = 0; i < n; i++)
        counts[data[i]+1] ++;
    for (int i = 0; i < N; i++)
        counts[i+1] += counts[i];
    for (int i = 0; i < n; i++)
        sa[counts[a[i]]++] = i;
    for (int i = 0; i < n; i++)
        rank[sa[i]] = i; 


}
