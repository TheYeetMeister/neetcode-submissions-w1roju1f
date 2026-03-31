class Solution:
    def numDecodings(self, s: str) -> int:
        first = 1
        second = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == "0":
                second = first
                first = 0
                continue

            if i != len(s) - 1 and (s[i] == "1" or s[i] == "2" and ord(s[i + 1]) <= ord("6")):
                temp = first
                first += second
                second = temp
            else:
                second = first

        return first



            