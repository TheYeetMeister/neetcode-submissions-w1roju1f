class Solution:
    def getFactors(self, x, n) -> tuple:
        factor = x
        if n < 0:
            factor = 1 / x
            n *= -1

        return (factor, n)

    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        res = 1
        x, n = self.getFactors(x, n)

        for i in range(n):
            res *= x

        return res