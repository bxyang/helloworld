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


class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        enum InputType {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };
        int transitionTable[][NUM_INPUTS] = {
            -1,  0,  2,  5,  1, -1,     // 0 next states for state "space"
            -1, -1, -1,  6, -1, -1,     // 1 next states for state "decimal point"
            -1, -1, -1,  5,  1, -1,     // 2 next states for state "sign before e"
            -1, -1, -1,  7, -1, -1,     // 3 next states for state "sign after e"
            -1, -1,  3,  7, -1, -1,     // 4 next states for state ¡°digit e¡±
            -1,  8, -1,  5,  6,  4,     // 5 next states for state "digit before e"
            -1,  8, -1,  6, -1,  4,     // 6 next states for state "digit point before e"
            -1,  8, -1,  7, -1, -1,     // 7 next states for state "digit after e"
            -1,  8, -1, -1, -1, -1,     // 8 next states for state "space after"
        };
        
        int state = 0;
        while (*s != '\0') {
            InputType inputType = INVALID;
            if (isspace(*s))
                inputType = SPACE;
            else if (*s == '+' || *s == '-')
                inputType = SIGN;
            else if (isdigit(*s))
                inputType = DIGIT;
            else if (*s == '.')
                inputType = DOT;
            else if (*s == 'e' || *s == 'E')
                inputType = EXPONENT;
        
            // Get next state from current state and input symbol
            state = transitionTable[state][inputType];
        
            // Invalid input
            if (state == -1) return false;
            else ++s;
        }
            // If the current state belongs to one of the accepting (final) states,
            // then the number is valid
            return state == 5 || state == 6 || state == 7 || state == 8;
    }
};
