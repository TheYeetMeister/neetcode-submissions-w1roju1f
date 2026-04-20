class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m = len(s)
        n = len(t)

        dp = {}

        def dfs(i, j):
            if (i, j) in dp:
                return dp[(i, j)]
            elif j == n:
                return 1
            elif i == m:
                return 0

            count = 0

            for k in range(i, m):
                if s[k] == t[j]:
                    count += dfs(k + 1, j + 1)

            dp[(i, j)] = count
            return dp[(i, j)]

        return dfs(0, 0)