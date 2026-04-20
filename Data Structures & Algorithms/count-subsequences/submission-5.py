class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m = len(s)
        n = len(t)

        dp = [1 for _ in range(m + 1)]

        for i in range(n - 1, -1, -1):
            newDp = [0 for _ in range(m + 1)]

            for j in range(m - 1, -1, -1):
                if s[j] == t[i]:
                    newDp[j] += dp[j + 1]
                
                newDp[j] += newDp[j + 1]
            
            dp = newDp

        return dp[0]