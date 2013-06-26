/*
 * =====================================================================================
 *
 *       Filename:  49.cc
 *
 *    Description:  str to int
 *
 *        Version:  1.0
 *        Created:  06/25/2013 04:52:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

enum Status {kValid = 0, kInvalid};
int g_status = kValid;

int str2int(const char* str) {
    g_status = kInvalid;
    long long num = 0;
    if ((str == NULL) || (str == '\0'))
        return num;
    const char* digit = str;
    bool is_negtive = false;
    if (*digit == '-') {
        is_negtive = true;
        digit++;
    }
    else if (*digit == '+')
        digit++;
    if (*digit != '\0')
        num = str2int_core(digit, is_negtive);
    return (int)num;
}

long long str2int_core(const char* digit, bool is_negtive) {
    long long num = 0;
    while (*digit != '\0') {
        int n = (int)(*digit);
        if ((n >= 48) && (n <= 57)) {
            int flag = is_negtive ? -1:1;
            num = num * 10 + flag*(n - 48);
            if (((is_negtive) && (num < (signed int)0x8000000)) || 
                ((!is_negtive) && (num > 0x7FFFFFFF))) {
                num = 0;
                break;
            }
        }
        else {
            num = 0;
            break;
        }
    }
    if (*digit == '\0') {
        g_status = kValid;
    }
    return num;
}
