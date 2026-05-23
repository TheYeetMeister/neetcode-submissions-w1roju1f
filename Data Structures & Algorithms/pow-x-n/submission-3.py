Factor = namedtuple('Factor', ['x', 'n'])

class Solution:
    def getFactors(self, x, n) -> tuple:
        factor = x
        if n < 0:
            factor = 1 / x
            n *= -1

        return (factor, n)

    def myPow(self, x: float, n: int) -> float:
        x, n = self.getFactors(x, n)

        factors = [Factor(x, 1)]

        while factors[-1].n < n:
            newX = factors[-1].x * factors[-1].x
            newN = 2 * factors[-1].n

            factors.append(Factor(newX, newN))

        res = 1
        buildUpN = 0
        currFactor = len(factors) - 1
        while buildUpN < n:
            while factors[currFactor].n + buildUpN > n:
                currFactor -= 1

            res *= factors[currFactor].x
            buildUpN += factors[currFactor].n

        return res