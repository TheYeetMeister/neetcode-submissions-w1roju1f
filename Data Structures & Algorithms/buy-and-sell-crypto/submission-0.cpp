class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxAmt = 0;

        int profit = 0;

        int currMin = prices[0];
        int right = 1;

        for (;right < prices.size(); ++right) {
            if (currMin > prices[right]) {
                currMin = prices[right];
            } else {
                profit = max(profit, prices[right] - currMin);
            }
        }

        return profit;
    }
};
