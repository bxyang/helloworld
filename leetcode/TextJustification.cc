/*
 * =====================================================================================
 *
 *       Filename:  TextJustification.cc
 *
 *    Description:  
        Given an array of words and a length L, format the text such that each line has exactly L characters 
        and is fully (left and right) justified.

        You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
        Pad extra spaces ' ' when necessary so that each line has exactly L characters.

        Extra spaces between words should be distributed as evenly as possible. 
        If the number of spaces on a line do not divide evenly between words, 
        the empty slots on the left will be assigned more spaces than the slots on the right.

        For the last line of text, it should be left justified and no extra space is inserted between words.

        For example,
        words: ["This", "is", "an", "example", "of", "text", "justification."]
        L: 16.

        Return the formatted lines as:

        [
           "This    is    an",
           "example  of text",
           "justification.  "
        ]
        Note: Each word is guaranteed not to exceed L in length.

        Corner Cases:
        A line other than the last line might contain only one word. What should you do in this case?
        In this case, that line should be left-justified.
 *
 *        Version:  1.0
 *        Created:  2013/7/30 13:05:05
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
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if (words.size() == 0)
            return ret;
        int p1 = 0;
        int p2 = 0;
        string tmp = words[0];
        int rem_l = L - tmp.length();
        for (int i = 1; i < words.size(); i++) {
            int tmp_rem = rem_l - words[i].length() - 1;
            if (tmp_rem > 0) {
                rem_l = tmp_rem;
                p2 = i;
            } else {
                if (tmp_rem == 0) {
                    p2 = i;
                    rem_l = 0;
                    i++;
                }
                int space_seg_num = p2 - p1;
                if (space_seg_num == 0) {
                    tmp = tmp + string(rem_l, ' ');
                    ret.push_back(tmp);
                } else {
                    int space_num = rem_l / space_seg_num + 1;
                    rem_l = rem_l % space_seg_num;
                    for (int j = p1 + 1; j <= p2; j++) {
                        if (rem_l > 0) {
                            tmp = tmp + string(space_num + 1, ' ') + words[j];
                            rem_l--;
                        } else {
                            tmp = tmp + string(space_num, ' ') + words[j];
                        }
                    }
                    ret.push_back(tmp);
                }
                if (i < words.size()) {
                    p1 = i;
                    p2 = i;
                    tmp = words[i];
                    rem_l = L - tmp.length();
                }
            }
        }
        
        if (rem_l >= 0) {
            for (int j = p1 + 1; j < words.size(); j++)
                tmp = tmp + ' ' + words[j];
            tmp += string(L-tmp.length(), ' ');
            ret.push_back(tmp);
        }
        return ret;
    }
};
