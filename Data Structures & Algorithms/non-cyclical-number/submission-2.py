class Solution:
    def isHappy(self, n: int) -> bool:
        def getSquaredVal(n):
            res = 0

            while n:
                res += (n % 10) ** 2
                n //= 10

            return res

        visited = set()

        while n not in visited:
            if n == 1:
                return True

            visited.add(n)
            n = getSquaredVal(n)

        return False
        