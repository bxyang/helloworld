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

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> st_i;
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            if (st_i.empty()) 
                st_i.push(i);
            else {
                if (height[i] > height[st_i.top()])
                    st_i.push(i);
                else if (height[i] < height[st_i.top()]) {
                    int itop;
                    while (!st_i.empty()) {
                        if (height[i] >= height[st_i.top()])
                            break;
                        itop = st_i.top();
                        int a = (i - itop)*height[itop];
                        maxArea = a > maxArea ? a : maxArea;
                        st_i.pop();
                    }
                    if (st_i.empty() || (height[i] > height[st_i.top()])) {
                        st_i.push(itop);
                        height[itop] = height[i];
                    }
                }
            }
        }
        
        while (!st_i.empty()) {
            int a = (height.size() - st_i.top())*height[st_i.top()];
            maxArea = a > maxArea ? a : maxArea;
            st_i.pop();
        }
        return maxArea;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> st;
        int i = 0;
        int maxArea = 0;
        while (i < height.size()) {
            if (st.empty() || height[st.top()] < height[i])
                st.push(i++);
            else {
                int start = st.top();
                st.pop();
                int width = (st.empty() ? i: i - st.top() - 1);
                int a = height[start] * width;
                maxArea = (a > maxArea) ? a : maxArea;
            }
        }
        
        while (!st.empty()) {
            int a = height[st.top()];
            st.pop();
            a = a * (st.empty() ? height.size(): height.size() - st.top() - 1);
            maxArea = (a > maxArea) ? a : maxArea;
        }
        
        return maxArea;
    }
};