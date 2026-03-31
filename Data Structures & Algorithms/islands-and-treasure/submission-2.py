class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        queue = deque()

        ROW = len(grid)
        COL = len(grid[0])

        for i in range(ROW):
            for j in range(COL):
                if grid[i][j] == 0:
                    queue.append((i, j))

        deltaDir = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        currStep = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                i, j = queue.popleft()

                if grid[i][j] < currStep:
                    continue

                grid[i][j] = currStep

                for k, m in deltaDir:
                    newI = i + k
                    newJ = j + m

                    if (newI < 0 or newI == ROW or
                        newJ < 0 or newJ == COL):
                            continue

                    queue.append((newI, newJ))
            
            currStep += 1