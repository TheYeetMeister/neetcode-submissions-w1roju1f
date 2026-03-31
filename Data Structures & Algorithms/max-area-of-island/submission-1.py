class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ROW: int = len(grid)
        COL: int = len(grid[0])

        deltaDir = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]
        def dfs(i: int, j: int):
            if (i < 0 or i == ROW or
                j < 0 or j == COL or
                grid[i][j] == 0
            ):
                return 0

            size = 1
            grid[i][j] = 0
            for k, m in deltaDir:
                size += dfs(i + k, j + m)
            
            return size

        res = 0
        for i in range(ROW):
            for j in range(COL):
                res = max(res, dfs(i, j))

        return res
