class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n = len(s)
        m = len(p)
        dp = {}

        def dfs(i, j):
            if (i, j) in dp:
                return dp[(i, j)]
            
            checker = False

            if i == -1 and j == -1:
                checker = True
            elif j == -1:
                checker = False
            elif s[i] == p[j] or p[j] == '.':
                checker = dfs(i - 1, j - 1)
            elif p[j] == '*':
                char = p[j - 1]
                checker = dfs(i, j - 2)

                for k in range(i, -1, -1):
                    if char != "." and char != s[k]:
                        break
                    
                    checker = dfs(k - 1, j - 2) or checker
            
            dp[(i, j)] = checker
            return dp[(i, j)]

        return dfs(n - 1, m - 1)

            