class Solution {
    int dfs(vector<int>& prices, int i, bool hasStock) {
        if (i >= prices.size()) {
            return 0;
        }

        if (hasStock) {
            int sell = prices[i] + dfs(prices, i + 2, false);
            int dontSell = dfs(prices, i + 1, true);
            return max(sell, dontSell);
        } else {
            int bought = dfs(prices, i + 1, true) - prices[i];
            int notBought = dfs(prices, i + 1, false);
            return max(bought, notBought);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, false);
    }
};
