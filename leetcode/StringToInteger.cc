/*
 * =====================================================================================
 *
 *       Filename:  StringToInteger.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/8/12 10:47:43
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
    int g_status;
    
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int mINVALID_INPUT = -1;
        const int mOVERFLOW = -2;
        const int mSUCCESS = 0;
        
        g_status = mSUCCESS;
        if (str == NULL) {
            g_status = mINVALID_INPUT;
            return 0;
        }
        
        while (*str == ' ')
            str++;
        
        int flag = 1;
        if ((*str == '-') || (*str == '+')) {
            flag = (*str == '-') ? -1:1;
            str++;
            if (*str == '\0') {
                g_status = mINVALID_INPUT;
                return 0;
            }
        }
        
        long long ret = 0;
        while (*str != '\0') {
            char c = (*str);
            if ((c < '0') || (c > '9')) {
                break;
            }
            ret = ret * 10 + flag * (c - 48);
            if (ret > int(0x7FFFFFFF)) {
                g_status = mOVERFLOW;
                return 0x7fffffff;
            }
            if (ret < int(0x80000000)) {
                g_status = mOVERFLOW;
                return 0x80000000;
            }
            
            str++;
        }
        
        return ret;
    }
};
