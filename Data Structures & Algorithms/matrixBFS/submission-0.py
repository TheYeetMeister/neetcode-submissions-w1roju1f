class Solution:
    def shortestPath(self, grid: List[List[int]]) -> int:
        queue = deque([(0, 0)])
        visited = set()
        m = len(grid)
        n = len(grid[0])

        path = 0

        delta = [
            [0, 1],
            [1, 0],
            [0, -1],
            [-1, 0]
        ]

        while queue:
            size = len(queue)

            for _ in range(size):
                i, j = queue.popleft()

                if i == m - 1 and j == n - 1:
                    return path
                
                if (i, j) in visited or grid[i][j] == 1:
                    continue
                visited.add((i, j))

                for k, u in delta:
                    if (i + k < 0 or i + k == m or
                        j + u < 0 or j + u == n):
                        continue
                    
                    queue.append((i + k, j + u))
            
            path += 1
                    
        return -1