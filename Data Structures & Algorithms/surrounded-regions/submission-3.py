class Solution:
    def solve(self, board: List[List[str]]) -> None:
        ROW: int = len(board)
        COL: int = len(board[0])

        deltaDir = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ] 

        def dfs(i: int, j: int):
            if (i < 0 or i == ROW or
                j < 0 or j == COL or
                board[i][j] == "X" or board[i][j] == "S"
            ):
                return
            
            board[i][j] = "S"

            for k, m in deltaDir:
                dfs(i + k, j + m)

        for i in range(ROW):
            dfs(i, 0)
            dfs(i, COL - 1)

        for j in range(COL):
            dfs(0, j)
            dfs(ROW - 1, j)

        for i in range(ROW):
            for j in range(COL):
                if board[i][j] == "S":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"

        

            
