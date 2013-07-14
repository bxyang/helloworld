/*
 * =====================================================================================
 *
 *       Filename:  BestTimeToBuyAndSellStock.cc
 *
 *    Description:  
        Say you have an array for which the ith element is the price of a given stock on day i.

        If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
        design an algorithm to find the maximum profit.
         
 *
 *        Version:  1.0
 *        Created:  2013/7/12 15:42:32
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
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
        return maxProfitCore(prices, 0, prices.size() -1);
    }
    
    int maxProfitCore(vector<int> &prices, int start, int end) {
        int max_idx = max_element(prices, start, end, max_cmp);
        int min_idx = max_element(prices, start, end, min_cmp);
        if (max_idx == min_idx)
            return 0;
        if (max_idx > min_idx)
            return prices[max_idx] - prices[min_idx];
        int ret1 = 0;
        int ret2 = 0;
        int ret3 = 0;
        if (max_idx > start)
            ret1 = prices[max_idx] - prices[max_element(prices, start, max_idx - 1, min_cmp)];
        if (min_idx < end)
            ret3 = prices[max_element(prices, min_idx + 1, end, max_cmp)] - prices[min_idx];
        if ((min_idx - max_idx) > 2)
            ret2 = maxProfitCore(prices, max_idx + 1, min_idx - 1);
        return (ret1 > ret2 ? ret1 : ret2) > ret3 ? (ret1 > ret2 ? ret1 : ret2): ret3;
    }
    
    int max_element(vector<int>& prices, int start, int end, bool (*cmp)(const int&, const int&)) {
        int ret = start;
        int key = prices[start];
        for (int i = start+1; i <= end; i++) {
            if (cmp(key, prices[i])) {
                ret = i;
                key = prices[i];
            }
        }
        return ret;
    }
    
    static bool max_cmp(const int& a1, const int& a2) {
        return a1 < a2;
    }
    static bool min_cmp(const int& a1, const int& a2) {
        return a1 > a2;
    }
};


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min = 0;
        int max_diff = 0;;
        int len = prices.size();
        for (int i = 0; i < len; i++) {
            if (prices[i] < prices[min])
                min = i;
            int diff = prices[i] - prices[min];
            if (diff > max_diff) {
                max_diff = diff;
            }
        }
        return max_diff;
    }
};

