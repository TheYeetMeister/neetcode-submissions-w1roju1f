class Solution:
    def rotateElem(self, n):
        limit = self._n - n - 1
        for i in range(limit - n):
            delta = [
                (n, n + i),
                (n + i, limit),
                (limit, limit - i),
                (limit - i, n)
            ]
            
            values = [0] * 4
            for cnt, (i, j) in enumerate(delta):
                values[cnt] = self._matrix[i][j]

            for cnt, (i, j) in enumerate(delta):
                self._matrix[i][j] = values[(3 + cnt) % 4]


    def rotate(self, matrix: List[List[int]]) -> None:
        self._matrix = matrix
        self._n = len(matrix)

        for i in range(self._n // 2 + 1):
            self.rotateElem(i)