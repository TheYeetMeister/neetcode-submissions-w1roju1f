class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        deltaDir = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        minHeap = [(0, 0, 0)]
        visited = set()
        ROW = len(grid)
        COL = len(grid[0])

        res = 0

        while minHeap:
            dist, i, j = heapq.heappop(minHeap)
            if (i, j) in visited:
                continue
            visited.add((i, j))
            
            res = max(grid[i][j], res)

            if i == ROW - 1 and j == COL - 1:
                break

            for k, m in deltaDir:
                iNew = i + k
                jNew = j + m
                if (iNew < 0 or iNew == ROW or
                    jNew < 0 or jNew == COL or
                    (iNew, jNew) in visited):
                    continue
                
                newDist = grid[iNew][jNew]
                heapq.heappush(minHeap, (newDist, iNew, jNew))
            

        return res


