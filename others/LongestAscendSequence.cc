/*
 * =====================================================================================
 *
 *       Filename:  LongestAscendSequence.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/9 19:13:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include<cstdio>
#include<cstdlib>

const int N = 100000;
int get_min(int* data, int n) {
    int ret = 0x7FFFFFFF;
    for (int i = 0; i < n; i++)
        ret = ret < data[i] ? ret : data[i];
    return ret;
}

int bi_search_less_than_max(int* data, int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right-left)/2;
        if (data[mid] >= target)
            right = mid - 1;
        else {
            left = mid;
			if (left == right - 1) {
				if (data[right] >= target)
					return left;
				else
					return right;
			}
		}
    }
	if (data[left] < target)
		return left;
	return -1;
} 

int longest_ascend_sequence(int* data, int n) {
    int max_value[N+1];
    max_value[0] = 0x80000000;
    max_value[1] = data[0];
    int len[N];
    for (int i = 0; i < n; i++)
        len[i] = 1;
    int max_len = 1;
    for (int i = 1; i < n; i++) {
        
        /*
        int j = max_len;
        for (; j > 0; j--) {
            if (max_value[j] < data[i]) {
                len[i] = j + 1;
                break;
            }
        }
        */
        int j = bi_search_less_than_max(max_value, max_len+1, data[i]);
        if (j == -1)
            continue;
		len[i] = j+1;
        if (len[i] > max_len) {
            max_len = len[i];
            max_value[len[i]] = data[i];
        } else if ((data[i] > max_value[j]) && (data[i] < max_value[j+1]))
            max_value[j+1] = data[i];
    }
    return max_len;
}


int main() {
    int n;
    int data[N];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &data[i]);
        int ret = longest_ascend_sequence(data, n);
        printf("%d\n", ret);
    }
    return 0;
}
