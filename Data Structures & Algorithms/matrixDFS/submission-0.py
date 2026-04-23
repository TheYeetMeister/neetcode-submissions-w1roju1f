class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        count = 0

        visited = set()

        n = len(grid)
        m = len(grid[0])

        delta = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        def dfs(i, j):
            if (i < 0 or i == n or
                j < 0 or j == m or
                grid[i][j] == 1 or
                (i, j) in visited):
                return 0
            elif i == n - 1 and j == m - 1:
                return 1

            visited.add((i, j))
            count = 0

            for k, u in delta:
                count += dfs(i + k, j + u)

            visited.remove((i, j))

            return count

        return dfs(0, 0)

