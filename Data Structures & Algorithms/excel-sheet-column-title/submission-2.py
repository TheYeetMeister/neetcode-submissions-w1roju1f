class Solution:
    numToLet = [chr(i + ord('A')) for i in range(26)]

    def convertToTitle(self, columnNumber: int) -> str:
        res = []

        while columnNumber > 0:
            columnNumber -= 1
            res += self.numToLet[columnNumber % 26]
            columnNumber //= 26

        return ''.join(reversed(res))

