/*
 * =====================================================================================
 *
 *       Filename:  BestTimeToBuyAndSellStockII.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/13 12:16:16
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
        map<int, int> fn;
        int len = prices.size();
        if (len <= 1)
            return 0;
        fn.insert(pair<int, int>(len,  0));
        fn.insert(pair<int, int>(len - 1,  0));
        return maxProfitCore(fn, prices, 0);
    }
    
    int maxProfitCore(map<int, int> &fn, vector<int> &prices, int n) {
        if (fn.find(n) != fn.end()) {
            return fn[n];
        }
        // n < prices.size() - 1
        int max = maxProfitCore(fn, prices, n+1);
        for (int j = n+1; j < prices.size(); j++) {
            int tmp = maxProfitCore(fn, prices, j) + prices[j] - prices[n];
            max = max > tmp ? max : tmp;
        }
        fn.insert(pair<int, int>(n, max));
        return max;       
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if (len <= 1)
            return 0;
        vector<pair<bool, int>> fn(len+1, pair<bool, int>(false, 0));
        fn[len] = pair<bool, int>(true, 0);
        fn[len-1] = pair<bool, int>(true, 0);
        return maxProfitCore(fn, prices, 0);
    }
    
    int maxProfitCore(vector<pair<bool, int> > &fn, vector<int> &prices, int n) {
        if (fn[n].first)
            return fn[n].second;
        // n < prices.size() - 1
        int max = maxProfitCore(fn, prices, n+1);
        for (int j = n+1; j < prices.size(); j++) {
            int tmp = maxProfitCore(fn, prices, j) + prices[j] - prices[n];
            max = max > tmp ? max : tmp;
        }
        fn[n] = pair<bool, int>(true, max);
        return max;       
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        int i = 0;
        int len = prices.size();
        if(len<2)
            return 0;
        for(i=1;i<len;++i)
        {
            if(prices[i]>prices[i-1])
            {
                result += prices[i]-prices[i-1];
            }
        }
        return result;
    }
};
