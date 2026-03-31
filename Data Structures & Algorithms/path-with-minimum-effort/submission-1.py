class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        highestDiff = 0
        minHeap = [(0, (0, 0))]
        visited = set()

        ROWS = len(heights)
        COLS = len(heights[0])

        step = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        while minHeap:
            top = heapq.heappop(minHeap)
            difference = top[0]
            coordinate = top[1]

            if coordinate in visited:
                continue

            visited.add(coordinate)

            x = coordinate[0]
            y = coordinate[1]

            highestDiff = max(difference,  highestDiff)

            print(coordinate, end=" ")
            print(difference)

            if ROWS - 1 == x and COLS - 1 == y:
                return highestDiff

            for i, j in step:
                newX = x + i
                newY = y + j
                newCoor = (newX, newY)

                if (newX == ROWS or newX < 0 or
                    newY == COLS or newY < 0):
                    continue

                newDiff = heights[newX][newY] - heights[x][y]

                heapq.heappush(minHeap, (abs(newDiff), newCoor))

        return -1