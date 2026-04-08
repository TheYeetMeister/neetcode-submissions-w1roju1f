class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        ROW = len(obstacleGrid)
        COL = len(obstacleGrid[0])

        row = [0 for _ in range(COL)]

        for i in range(COL - 1, -1, -1):
            if obstacleGrid[ROW - 1][i]:
                break
            row[i] = 1

        for i in range(ROW - 2, -1, -1):
            newRow = [0 for _ in range(COL)]

            for j in range(COL - 1, -1, -1):
                if obstacleGrid[i][j]:
                    continue
                newRow[j] += row[j]

                if j < COL - 1:
                    newRow[j] += newRow[j + 1]

            row = newRow
                

        return row[0]
            
