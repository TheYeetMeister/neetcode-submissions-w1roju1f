class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        players = ["Alice", "Bob"]
        n = len(stoneValue)
        dp = [float("-inf") for _ in range(n + 1)]
        dp[n] = 0

        for i in range(n - 1, -1, -1):
            dp[i] = stoneValue[i] - dp[i + 1]

            if i < n - 1:
                dp[i] = max(stoneValue[i] + stoneValue[i + 1] - dp[i + 2], dp[i])
            
            if i < n - 2:
                dp[i] = max(stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3], 
                    dp[i])

        if dp[0] > 0:
            return players[0]
        elif dp[0] < 0:
            return players[1]
        else:
            return "Tie"