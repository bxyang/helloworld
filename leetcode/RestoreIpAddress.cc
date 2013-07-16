/*
 * =====================================================================================
 *
 *       Filename:  RestoreIpAddress.cc
 *
 *    Description:  
        Given a string containing only digits, restore it by returning all possible valid IP address combinations.

        For example:
        Given "25525511135",

        return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


 *        Version:  1.0
 *        Created:  2013/7/16 9:47:09
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
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return restoreIpAddressCore(s, 4);
    }
    
    vector<string> restoreIpAddressCore(string s, int n) {
        int len = s.length();
        vector<string> ret;
        if (len == 0)
            return ret;
        if (n == 1) {
            if ((len > 1) && (s[0] == '0'))
                return ret;
            int v = atoi(s.c_str());
            if (v <= 255)
                ret.push_back(s);
            return ret;
        }
        int min = (len < 3) ? len : 3;
        if (s[0] == '0') {
            min = 1;
        }
        for (int i = 1; i <= min; i++) {
            vector<string> tail = restoreIpAddressCore(s.substr(i), n-1);
            string head = s.substr(0, i);
            int v = atoi(head.c_str());
            if (v > 255)
                break;
            head += ".";
            for(vector<string>::iterator it = tail.begin(); it != tail.end(); it++) {
                ret.push_back(head + (*it));                
            }            
        }
        return ret;
    }
};

