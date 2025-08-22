class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price = prices[0];
        int max_profit = 0;

        for(int i = 1;i<n;i++) {
            if(prices[i]<min_price) {
                min_price = prices[i];
                continue;
            }
            int profit_today = prices[i] - min_price;
            max_profit = max(max_profit,profit_today);
        }

        return max_profit;
    }
};