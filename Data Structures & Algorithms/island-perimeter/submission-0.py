class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        deltaDir = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        self.permiter: int = 0
        visited = set()

        ROW: int = len(grid)
        COL: int = len(grid[0])

        def dfs(i: int, j: int):
            if (i < 0 or i == ROW or
                j < 0 or j == COL or
                grid[i][j] == 0
            ):
                return False

            if (i, j) in visited:
                return True
            
            visited.add((i, j))

            for k, m in deltaDir:
                if not dfs(i + k, j + m):
                    self.permiter += 1
            
            return True
            
        for i in range(ROW):
            for j in range(COL):
                if dfs(i, j):
                    return self.permiter
            
        return 0