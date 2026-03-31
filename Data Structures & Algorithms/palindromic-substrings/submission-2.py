class Solution:
    def countSubstrings(self, s: str) -> int:
        res = 0
        n = len(s)

        for i in range(n):
            k = i
            m = i

            while k >= 0 and m < n and s[k] == s[m]:
                res += 1

                k -= 1
                m += 1

            k = i
            m = i + 1

            while k >= 0 and m < n and s[k] == s[m]:
                res += 1

                k -= 1
                m += 1

        return res