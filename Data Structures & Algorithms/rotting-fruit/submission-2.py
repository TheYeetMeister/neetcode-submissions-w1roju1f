class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        freshOrangeCount = 0
        rottedCount = 0
        time = 0
        queue = deque()

        ROW = len(grid)
        COL = len(grid[0])

        for i in range(ROW):
            for j in range(COL):
                match grid[i][j]:
                    case 1:
                        freshOrangeCount += 1
                    case 2:
                        queue.append((i, j))

        deltaDir = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        visited = set()

        while queue:
            size = len(queue)

            for _ in range(size):
                i, j = queue.popleft()

                if (i, j) in visited or grid[i][j] != 2:
                    continue
                
                visited.add((i, j))

                for k, m in deltaDir:
                    if (i + k < 0 or i + k == ROW or
                        j + m < 0 or j + m == COL or
                        grid[i + k][j + m] != 1
                    ):
                        continue

                    rottedCount += 1
                    grid[i + k][j + m] = 2
                    queue.append((i + k, j + m))
            
            if queue:
                time += 1

        return time if freshOrangeCount == rottedCount else -1
                