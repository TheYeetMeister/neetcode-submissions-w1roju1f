class Solution {
    int dfs(int amount, vector<int>& coins, int i) {
        if (amount < 1) {
            return amount == 0;
        }

        int cnt = 0;
        for (; i < coins.size(); ++i) {
            cnt += dfs(amount - coins[i], coins, i);
        }
        return cnt;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin: coins) {
            for (int i = 0; i < amount; ++i) {
                if (i + coin < dp.size()) {
                    dp[i + coin] += dp[i];
                }
            }
        }

        return dp.back();
    }
};
