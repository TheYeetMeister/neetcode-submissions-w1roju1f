class Solution:
    numToLet = [chr(i + ord('A')) for i in range(26)]

    def convertToTitle(self, columnNumber: int) -> str:
        columnNumber -= 1
        res = ""

        while columnNumber >= 0:
            res += self.numToLet[columnNumber % 26]
            columnNumber //= 26
            columnNumber -= 1

        return res[::-1]

