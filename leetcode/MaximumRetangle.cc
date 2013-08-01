/*
 * =====================================================================================
 *
 *       Filename:  MaximumRetangle.cc
 *
 *    Description: 
 *          Given a 2D binary matrix filled with 0's and 1's, 
 *          find the largest rectangle containing all ones and return its area. 
 *
 *        Version:  1.0
 *        Created:  2013/8/1 12:44:39
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
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int row_num = matrix.size();
        if (row_num == 0)
            return 0;
        int col_num = matrix[0].size();
        vector<vector<int> > heights = vector<vector<int> >(row_num,
            vector<int>(col_num, 0));
        for (int j = 0; j < col_num; j++) {
            if (matrix[0][j] == '1') {
                heights[0][j] = 1;    
            }
        }
        for (int j = 0; j < col_num; j++) {
            for (int i = 1; i < row_num; i++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = 1 + heights[i-1][j];    
                }
            }
        }
        int ret = 0;
        for (int j = 0; j < row_num; j++) {
            int tmp = maxRetangle(heights[j]);
            ret = ret > tmp ? ret : tmp;
        }
        
        return ret;
    }
    
    int maxRetangle(vector<int> &num){
        int ret = 0;
        stack<int> h_st;
        stack<int> i_st;
        for (int i = 0; i < num.size(); i++) {
            if (h_st.empty()) {
                h_st.push(num[i]);
                i_st.push(i);
            } else {
                int h = num[i];
                int hs = h_st.top();
                int is = i_st.top();
                if (h > hs) {
                    h_st.push(num[i]);
                    i_st.push(i);
                } else if (h < hs) {
                    while (! h_st.empty()) {
                        hs = h_st.top();
                        if (hs <= h)
                            break;
                        is = i_st.top();
                        int tmp_area = (i - is)*hs;
                        ret = ret > tmp_area ? ret : tmp_area;
                        h_st.pop();
                        i_st.pop();
                    }
                    
                    if (h_st.empty() || hs < h) {
                        h_st.push(h);
                        i_st.push(is);
                    }
                }
            }
        }
        
        while (! h_st.empty()) {
            int hs = h_st.top();
            int is = i_st.top();
            int tmp_area = hs*(num.size() - is);
            ret = ret > tmp_area ? ret : tmp_area;
            h_st.pop();
            i_st.pop();
        }
        return ret;
    }
};
