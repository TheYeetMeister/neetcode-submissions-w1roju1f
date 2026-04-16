class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n = len(s1)
        m = len(s2)

        if n + m != len(s3):
            return False

        dp = [[False for _ in range(m + 1)] for _ in range(n + 1)]
        dp[n][m] = True

        for i in range(n, -1, -1):
            for j in range(m, -1, -1):
                if i < n and s1[i] == s3[i + j]:
                    dp[i][j] = dp[i][j] or dp[i + 1][j]

                if j < m and s2[j] == s3[i + j]:
                    dp[i][j] = dp[i][j] or dp[i][j + 1]
            
        return dp[0][0]