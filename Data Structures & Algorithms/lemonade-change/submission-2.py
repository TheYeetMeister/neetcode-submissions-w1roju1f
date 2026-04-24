class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        tenBills = 0
        fiveBills = 0

        for bill in bills:
            if bill == 5:
                fiveBills += 1
            elif bill == 10:
                if fiveBills == 0:
                    return False
                tenBills += 1
                fiveBills -= 1
            elif fiveBills >= 3:
                fiveBills -= 3
            elif fiveBills > 0 and tenBills > 0:
                tenBills -= 1
                fiveBills -= 1
            else:
                return False

        
        return True