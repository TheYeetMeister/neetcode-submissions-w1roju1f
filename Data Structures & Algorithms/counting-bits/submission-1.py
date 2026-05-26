class Solution:
    def countBits(self, n: int) -> List[int]:
        def bitAmt(n: int):
            res = 0
            while n:
                res += 1
                n = n & (n - 1)

            return res

        res = [0] * (n + 1)

        for i in range(n + 1):
            res[i] = bitAmt(i)

        return res

