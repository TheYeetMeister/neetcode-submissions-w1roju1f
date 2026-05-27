class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) < len(b):
            a, b = b, a

        a = a[::-1]
        b = b[::-1]

        carry = 0
        res = []

        n = len(a)
        m = len(b)
        for i in range(m):
            value = int(a[i]) + int(b[i]) + carry
            carry = value // 2
            value %= 2

            res.append(str(value))

        for j in range(m, n):
            value = int(a[j]) + carry
            carry = value // 2
            value %= 2

            res.append(str(value))

        if carry:
            res.append(str(carry))

        return ''.join(reversed(res))

        

        