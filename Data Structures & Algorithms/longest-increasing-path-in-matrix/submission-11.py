class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        delta = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        m = len(matrix)
        n = len(matrix[0])

        def dfs(i, j, prevNum, dp):
            if (i < 0 or i == m or
                j < 0 or j == n or
                prevNum >= matrix[i][j]):
                return 0

            if dp[i][j] != float("-inf"):
                return dp[i][j]

            maxRes = 0

            for k, g in delta:
                maxRes = max(maxRes, 1 + dfs(i + k, j + g, matrix[i][j], dp))
            
            dp[i][j] = maxRes
            return dp[i][j]

        res = 0
        dp = [[float("-inf") for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                res = max(res, dfs(i, j, float("-inf"), dp))

        return res
            

