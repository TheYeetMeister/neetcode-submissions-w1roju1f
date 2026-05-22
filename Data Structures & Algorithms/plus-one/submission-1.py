class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res = []

        digits[-1] += 1

        carry = 0
        for i in reversed(digits):
            if carry:
                i += 1

            carry = i // 10
            res.append(i % 10)
        
        if carry:
            res.append(1)

        return res[::-1]
