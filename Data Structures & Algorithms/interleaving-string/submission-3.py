class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        dp = {}
        def dfs(i, j):
            if (i, j) in dp:
                return dp[(i, j)]
            elif i == len(s1) and j == len(s2) and i + j == len(s3):
                return True
            elif i + j >= len(s3):
                return False

            value = False
            if i < len(s1) and s1[i] == s3[i + j]:
                value = value or dfs(i + 1, j)

            if j < len(s2) and s2[j] == s3[i + j]:
                value = value or dfs(i, j + 1)

            dp[(i, j)] = value
            return dp[(i, j)]
            
        return dfs(0, 0)