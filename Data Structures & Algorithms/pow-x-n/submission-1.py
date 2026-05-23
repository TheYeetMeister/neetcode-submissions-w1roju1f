class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        res = 1
        factor = x
        if n < 0:
            factor = 1 / x
            n *= -1

        for i in range(n):
            res *= factor

        return res