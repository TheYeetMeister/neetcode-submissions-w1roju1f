class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        m = len(matrix[0])
        def circleAround(i, res):
            limitN = n - i
            limitM = m - i

            res.append(matrix[i][i])

            for k in range(i + 1, limitM):
                res.append(matrix[i][k])

            for q in range(i + 1, limitN):
                res.append(matrix[q][limitM - 1])

            if i == limitN - 1 or i == limitM - 1:
                return
            
            for k in range(limitM - 2, i - 1, -1):
                res.append(matrix[limitN - 1][k])

            for q in range(limitN - 2, i, -1):
                res.append(matrix[q][i])

        res = []

        minLength = min(n, m)
        for i in range(minLength // 2 + minLength % 2):
            circleAround(i, res)

        return res
