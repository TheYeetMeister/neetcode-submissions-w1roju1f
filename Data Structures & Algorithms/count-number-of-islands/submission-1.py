class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROW = len(grid)
        COL = len(grid[0])

        deltaDif = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]
        def dfs(i: int, j: int):
            if (i < 0 or i == ROW or
                j < 0 or j == COL or
                grid[i][j] == "0"):
                return
            
            
            grid[i][j] = "0"
            for k, m in deltaDif:
                dfs(i + k, j + m)
        
        count: int = 0
        for i in range(ROW):
            for j in range(COL):
                if grid[i][j] == "1":
                    count += 1
                    dfs(i, j)
        
        return count