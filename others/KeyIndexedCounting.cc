/*
 * =====================================================================================
 *
 *       Filename:  KeyIndexedCounting.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/15 16:46:15
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
#include<string.h>
#include<list>
#include<iterator>
using namespace std;


const int N = 128;
void key_indexed_counting_sort(char data[], int n) {
    int counts[N];
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < n; i++)
        counts[data[i] + 1]++;
    for (int i = 0; i < N; i++)
        counts[i+1] += counts[i];
    
    int* sa = new int[n];
    for (int i = 0; i < n; i++)
        sa[counts[data[i]]++] = data[i]; 
    for (int i = 0; i < n; i++)
        data[i] = sa[i];
}

int main() {
    char data[100];
    scanf("%s\n", data);
    key_indexed_counting_sort(data, strlen(data));
    printf("%s\n", data);
    return 0;
}
