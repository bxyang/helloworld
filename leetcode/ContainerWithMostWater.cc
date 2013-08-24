/*
 * =====================================================================================
 *
 *       Filename:  ContainerWithMostWater.cc
 *
 *    Description:  
        Given n non-negative integers a1, a2, ..., an, 
        where each represents a point at coordinate (i, ai). n vertical lines are drawn 
        such that the two endpoints of line i is at (i, ai) and (i, 0). 
        Find two lines, which together with x-axis forms a container, 
        such that the container contains the most water.

        Note: You may not slant the container.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/21 19:16:42
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
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        int n = height.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = (height[i] < height[j] ? height[i] : height[j])*(j-i);
                ret = (ret < t ? t : ret);
            }
        }
        return ret;
    }
};


class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        int n = height.size();
        int p1 = 0;
        int p2 = n - 1;
        while (p1 < p2) {
            int n = (height[p1] < height[p2] ? height[p1] : height[p2])*(p2-p1);
            ret = (ret < n) ? n:ret;
            if (height[p2] >= height[p1])
                p1++;
            else
                p2--;
        }
        return ret;
    }
};
