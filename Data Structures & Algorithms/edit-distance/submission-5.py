class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        dp = [m - i for i in range(m + 1)]

        for i in range(n - 1, -1, -1):
            newDp = [0 for _ in range(m + 1)]
            newDp[-1] = n - i

            for j in range(m - 1, -1, -1):
                if word1[i] == word2[j]:
                    newDp[j] = dp[j + 1]
                else:
                    newDp[j] = 1 + min(newDp[j + 1], dp[j], dp[j + 1])

            dp = newDp

        return dp[0]