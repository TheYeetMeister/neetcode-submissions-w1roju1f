class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        zeroed = set()
        n = len(matrix)
        m = len(matrix[0])

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    zeroed.add((i, j))

        
        def zero(i, j):
            for k in range(n):
                matrix[k][j] = 0

            for q in range(m):
                matrix[i][q] = 0
        
        for i, j in zeroed:
            zero(i, j)
        