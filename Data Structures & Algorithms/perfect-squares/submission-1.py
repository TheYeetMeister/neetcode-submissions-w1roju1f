class Solution:
    def numSquares(self, n: int) -> int:
        values = []

        i = 1
        while i * i <= n:
            values.append(i * i)
            i += 1
        
        dp = [n + 1 for _ in range(n + 1)]

        dp[0] = 0

        for i in range(n):
            for j in values:
                if i + j > n:
                    continue

                dp[i + j] = min(dp[i] + 1, dp[i + j])
                
        return dp[-1]

