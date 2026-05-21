class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        m = len(matrix[0])

        rowZero = set()
        colZero = set()

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    rowZero.add(i)
                    colZero.add(j)

        def zeroRow(i):
            for j in range(m):
                matrix[i][j] = 0

        def zeroCol(i):
            for j in range(n):
                matrix[j][i] = 0
        
        for i in rowZero:
            zeroRow(i)

        for j in colZero:
            zeroCol(j)
            
        