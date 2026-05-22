class Solution:
    def romanToInt(self, s: str) -> int:
        romanDict = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        largestVal = 0
        res = 0
        n = len(s)

        for i in range(n):
            val = romanDict[s[n - i - 1]]

            if val > largestVal:
                largestVal = val

            if largestVal > val:
                res -= val
            else:
                res += val

        return res