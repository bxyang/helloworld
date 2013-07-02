/*
 * =====================================================================================
 *
 *       Filename:  ValidNumber.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/1 19:12:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while ((*s != '\0') && (*s == ' '))
            s++;
        if (*s == '\0')
            return false;
        const char* p_end = s + strlen(s);
        while (*(p_end - 1) == ' ')
            p_end --;
        if ((*s == '-') || (*s == '+'))
            s++;
    	if (s == p_end)
			return false;
		bool flag_point = false;
		if (!isDigit(*s)) {
			if (*s != '.')
				return false;
			s++;
			flag_point = true;
			if(!isDigit(*s))
				return false;
			s++;
		}
        while (s != p_end) {
            if (isDigit(*s))
                s++;
            else {
                if (*s == '.') {
                    if (flag_point)
                        return false;
                    flag_point = true;
                    s++;
                }
                else if (*s == 'e') {
                    s++;
                    if (s == p_end)
                        return false;
                    return isInt(s, p_end);
                }
                else
                    return false;
            }
        }
        return true;
    }
    
    bool isInt(const char* s, char const* p_end) {
        if ((*s == '-') || (*s == '+')) {
            s++;
            if (s == p_end)
                return false;
        }
        while (s != p_end) {
            if (!isDigit(*s))
                return false;
            s++;
        }
        return true;
    }
    
    inline bool isDigit(char c) {
        if ((c >= '0') && (c <= '9'))
            return true;
        return false;
    }
};



