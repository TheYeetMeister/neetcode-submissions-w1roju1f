class Solution {
    int backtrack(vector<int>& coins, int amount, int i) {
        if (amount == 0) {
            return 0;
        }

        int minAmt = INT_MAX;
        for (; i < coins.size(); ++i) {
            if (coins[i] > amount) {
                continue;
            }

            int sub = backtrack(coins, amount - coins[i], i);

            if (sub != INT_MAX) {
                minAmt = min(minAmt, 1 + sub);
            }
        }

        return minAmt;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < amount; ++i) {
            if (dp[i] == INT_MAX) {
                continue;
            }

            for (int coin: coins) {
                if (i > amount + 1 - coin) {
                    continue;
                }

                dp[coin + i] = min(dp[coin + i], dp[i] + 1);
            }
        }

        return (dp.back() != INT_MAX) ? dp.back(): -1;
    }
};
