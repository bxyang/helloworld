/*
 * =====================================================================================
 *
 *       Filename:  LargestRetangleInHistogram.cc
 *
 *    Description:  
        Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
        find the area of largest rectangle in the histogram.

        For example,
        Given height = [2,1,5,6,2,3],
        return 10.
 *
 *
 *        Version:  1.0
 *        Created:  2013/7/31 16:56:02
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
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        for (int i = 0; i < height.size(); i++) {
            
            int h = height[i];
            int w = 1;
            for (int j = i-1; j >=0 ; j--) {
                if (height[j] >= h)
                    w++;
                else
                    break;
            }
            
            for (int j = i+1; j < height.size() ; j++) {
                if (height[j] >= h)
                    w++;
                else
                    break;
            }
            if (ret < w*h)
                ret = w*h;            
        }
        return ret;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        stack<int> h_stack;
        stack<int> i_stack;
        for (int i = 0; i < height.size(); i++) {
            int h = height[i];
            if (h_stack.empty()) {
                h_stack.push(h);
                i_stack.push(i);
            } else {
                int ht = h_stack.top();
                if (h > ht) {
                    h_stack.push(h);
                    i_stack.push(i);
                } else if (h < ht) {
                    /*
                    int it = i_stack.top();
                    int tmp_area = (i - it)*ht;
                    ret = (ret > tmp_area) ? ret : tmp_area;
                    h_stack.pop();
                    i_stack.pop();
                    */
                    int it;
                    while (! h_stack.empty()) {
                        ht = h_stack.top();
                        if (ht <= h)
                            break;
                        it = i_stack.top();
                        int tmp_area = (i - it)*ht;
                        ret = (ret > tmp_area) ? ret : tmp_area;
                        h_stack.pop();
                        i_stack.pop();
                    }
                    if (h_stack.empty() || ht < h) {
                        h_stack.push(h);
                        i_stack.push(it);
                    }
                }
            }
        }
        
        while (! h_stack.empty()) {
            int ht = h_stack.top();
            int it = i_stack.top();
            int tmp_area = (height.size() - it)*ht;
            ret = (ret > tmp_area) ? ret : tmp_area;    
            h_stack.pop();
            i_stack.pop();
        }
        return ret;
    }
};
