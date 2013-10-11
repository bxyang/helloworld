class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if (n < 2)
            return 0;
        vector<int> pre(n, 0);
        int min = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] < min) {
                pre[i] = pre[i-1];
                min = prices[i];
            } else {
                pre[i] = prices[i] - min;
                pre[i] = (pre[i] > pre[i-1] ? pre[i] : pre[i-1]);
            }
        }
        
        vector<int> post(n, 0);
        int max = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (prices[i] > max) {
                post[i] = post[i+1];
                max = prices[i];
            } else {
                post[i] = max - prices[i];
                post[i] = (post[i] > post[i+1] ? post[i] : post[i+1]);
            }
        }
        
        int ret = 0;
        for (int i = 0; i < (n-1); i++) {
            int t = pre[i] + post[i+1];
            ret = ret > t ? ret : t;
        }
        ret = (ret > pre[n-1] ? ret : pre[n-1]);
        return ret;
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if (len < 2)
            return 0;
        vector<int> ga(len);
        vector<int> gb(len);
        vector<int>::iterator it = prices.begin();
        vector<int>::iterator ita = ga.begin();
        int min = (*it);
        (*ita) = 0;
        it++;
        ita++;
        for (; it != prices.end(); it++, ita++) {
            min = (min < (*it)) ? min : (*it);
            (*ita) = max(*(prev(ita)), (*it) - min);
        }
        
        vector<int>::reverse_iterator r_it = prices.rbegin();
        vector<int>::reverse_iterator r_itb = gb.rbegin();
        int max = (*r_it);
        (*r_itb) = 0;
        r_it++;
        r_itb++;
        for (; r_it != prices.rend(); r_it++, r_itb++){
            max = (max > (*r_it)) ? max : (*r_it);
            (*r_itb) = ::max(*(prev(r_itb)), max - (*r_it));
        }
        
        int max_profit = 0;
        for (int i = 0; i < (len - 1); i++)
            max_profit = ::max(max_profit, ga[i]+gb[i+1]);
        max_profit = ::max(max_profit, ga[len -1]);
        return max_profit;
    }
};
