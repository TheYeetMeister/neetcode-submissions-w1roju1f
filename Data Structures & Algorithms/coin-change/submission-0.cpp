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
        int res = backtrack(coins, amount, 0);

        return (res == INT_MAX) ? -1 : res;
    }
};
