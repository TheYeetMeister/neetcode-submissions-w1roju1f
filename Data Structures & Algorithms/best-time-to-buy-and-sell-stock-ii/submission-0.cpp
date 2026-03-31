class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> res(prices.size() + 1);
        vector<int> hasStock(prices.size() + 1);
        for (int i = prices.size() - 1; i >= 0; --i) {
            hasStock[i] = max(res[i + 1] + prices[i], hasStock[i + 1]);
            res[i] = max(res[i + 1], hasStock[i + 1] - prices[i]);
        }

        return res[0];
    }
};