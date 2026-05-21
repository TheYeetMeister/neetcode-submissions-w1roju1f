class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        m = len(matrix[0])

        rowZero = [False] * n
        colZero = [False] * m

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    rowZero[i] = True
                    colZero[j] = True

        def zeroRow(i):
            for j in range(m):
                matrix[i][j] = 0

        def zeroCol(i):
            for j in range(n):
                matrix[j][i] = 0
        
        for i in range(n):
            if rowZero[i]:
                zeroRow(i)

        for j in range(m):
            if colZero[j]:
                zeroCol(j)
            
        