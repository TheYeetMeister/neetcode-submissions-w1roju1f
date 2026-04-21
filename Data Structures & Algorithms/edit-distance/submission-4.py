class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        dp = {}

        def dfs(i, j):
            if i == n:
                return m - j
            elif j == m:
                return n - i
            elif (i, j) in dp:
                return dp[(i, j)]

            if word1[i] == word2[j]:
                dp[(i, j)] = dfs(i + 1, j + 1)
            else:
                delete = dfs(i + 1, j)
                insert = dfs(i, j + 1)
                replace = dfs(i + 1, j + 1)
                dp[(i, j)] = 1 + min(delete, insert, replace)

            return dp[(i, j)]

        return dfs(0, 0)