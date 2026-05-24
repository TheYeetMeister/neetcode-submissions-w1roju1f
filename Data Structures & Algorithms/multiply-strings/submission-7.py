class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
            
        def multiplyOneNum(num1: str, numChar: str, leadingZeroes: int):
            carry = 0
            reversedRes = ["0"] * leadingZeroes
            
            factor = int(numChar)
            for i in reversed(num1):
                value = int(i)

                newValue = factor * value + carry
                carry = newValue // 10
                reversedRes.append(str(newValue % 10))

            if carry:
                reversedRes.append(str(carry))

            return reversedRes

        
        def addValues(reversedNum1 :str, reversedNum2: str):
            carry = 0
            n = len(reversedNum1)
            m = len(reversedNum2)

            res = []
            for i in range(max(n, m)):
                value = carry

                if i < n:
                    value += int(reversedNum1[i])

                if i < m:
                    value += int(reversedNum2[i])

                res.append(str(value % 10))
                carry = value // 10

            if carry:
                res.append(str(carry))

            return res

        m = len(num2)
        res = multiplyOneNum(num1, num2[m - 1], 0)

        for i in range(1, len(num2)):
            addedValue = multiplyOneNum(num1, num2[m - i - 1], i)

            res = addValues(res, addedValue)

        return ''.join(reversed(res))



