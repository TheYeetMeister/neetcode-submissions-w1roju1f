class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = amount
        dp = [0 for _ in range(n + 1)]
        dp[0] = 1

        for coin in coins:
            for j in range(n - coin + 1):
                dp[j + coin] += dp[j]

        return dp[n]