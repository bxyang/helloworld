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
