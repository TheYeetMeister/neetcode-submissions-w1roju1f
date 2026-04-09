class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        row = [0] *  n

        currSum = 0
        for i in range(n - 1, -1, -1):
            currSum += grid[m - 1][i]
            row[i] = currSum
        
        for i in range(m - 2, -1, -1):
            newRow = [0] * n
            newRow[-1] = grid[i][-1] + row[-1]

            for j in range(n - 2, -1, -1):
                newRow[j] = grid[i][j] + min(newRow[j + 1], row[j])

            row = newRow

        return row[0]


        