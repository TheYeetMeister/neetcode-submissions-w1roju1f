class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        col = set()
        diagRight = set()
        diagLeft = set()
        board = []
        res = []

        def dfs(i: int) -> bool:
            if i == n:
                res.append(board.copy())
                return

            for j in range(n):
                if (not j in col and
                    not i - j in diagRight and
                    not j + i in diagLeft):
                    col.add(j)
                    diagRight.add(i - j)
                    diagLeft.add(j + i)
                    
                    line = ['.' for _ in range(n)]
                    line[j] = 'Q'

                    board.append(''.join(line))
                    dfs(i + 1)
                    board.pop()

                    col.remove(j)
                    diagRight.remove(i - j)
                    diagLeft.remove(j + i)

        dfs(0)
        return res
                    