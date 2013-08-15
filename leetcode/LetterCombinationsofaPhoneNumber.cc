/*
 * =====================================================================================
 *
 *       Filename:  LetterCombinationsofaPhoneNumber.cc
 *
 *    Description:  
 *
        Given a digit string, return all possible letter combinations that the number could represent.

        A mapping of digit to letters (just like on the telephone buttons) is given below.

        Input:Digit string "23"
        Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
        Note:
        Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 *        Version:  1.0
 *        Created:  2013/8/14 19:34:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict  
 *
 * =====================================================================================
 */

class Solution {
    const char *num2letter[8] = {"abc", "def", "ghi", 
        "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        int len = 0;
        for (string::iterator it = digits.begin(); it != digits.end(); it++) {
            if ((*it != '1') && (*it != '0'))
                len++;
        }
        if (len == 0) {
            ret.push_back("");
            return ret;
            
        }
        string comb(len, ' ');
        letterCombinations(digits, 0, comb, 0, ret);
        return ret;
    }
    
    void letterCombinations(string digits, int p1, string comb, int p2, vector<string> &ret) {
        if (p1 == digits.length()) {
            ret.push_back(comb); 
            return;
        }
        if ((digits[p1] == '1') || (digits[p1] == '0'))
            return letterCombinations(digits, p1+1, comb, p2, ret);
        const char* q = num2letter[digits[p1] - '2'];
        while (*q != '\0') {
            comb[p2] = (*q);
            letterCombinations(digits, p1+1, comb, p2+1, ret);
            q++;
        }
    }
};
