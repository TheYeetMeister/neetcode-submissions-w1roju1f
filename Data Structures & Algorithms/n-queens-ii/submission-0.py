class Solution:
    def totalNQueens(self, n: int) -> int:
        col = set()
        diagRight = set()
        diagLeft = set()

        self.res = 0

        def dfs(i: int):
            if i == n:
                self.res += 1
                return

            for j in range(n):
                if (not j in col and
                    not i - j in diagRight and
                    not i + j in diagLeft):
                    col.add(j)
                    diagRight.add(i - j)
                    diagLeft.add(i + j)

                    dfs(i + 1)

                    col.remove(j)
                    diagRight.remove(i - j)
                    diagLeft.remove(i + j)

        dfs(0)

        return self.res
        