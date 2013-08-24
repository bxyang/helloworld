/*
 * =====================================================================================
 *
 *       Filename:  ImplementstrStr.cc
 *
 *    Description:  
        Implement strStr().

        Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/24 12:31:44
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
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int needle_len = strlen(needle);
        int* next = new int[needle_len];
        get_next(needle, next, needle_len);
        int i = 0;
        int j = 0;
        char* p1 = haystack;
        char* p2 = needle;
        while ((*p1 != '\0') && (*p2 != '\0')){
            if (*p1 == *p2) {
                p1++;
                p2++;
                i++;
                j++;
            } else {
                j = next[j];
                p2 = needle + j;
                if (j == -1) {
                    p1++;
                    p2++;
                    i++;
                    j++;
                } 
            }
        }
        if (*p2 != '\0')
            return NULL;
        return p1 - j;
    }
    
    void get_next(char* needle, int* next, int n) {
        next[0] = -1;
        int k = -1;
        int j = 0; 
        n--;
        while (j < n) {
            if ((k == -1) || (needle[k] == needle[j])) {
                j++;
                next[j] = k + 1;
                k++;
            } else {
                k = next[k];
            }
        }
        return;
    }
};
