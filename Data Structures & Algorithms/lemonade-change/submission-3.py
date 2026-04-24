class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        tenBills = 0
        fiveBills = 0

        for bill in bills:
            match bill:
                case 5:
                    fiveBills += 1
                case 10:
                    if fiveBills == 0:
                        return False
                    fiveBills -= 1
                    tenBills += 1
                case _:
                    if tenBills > 0 and fiveBills > 0:
                        tenBills -= 1
                        fiveBills -= 1
                    elif fiveBills >= 3:
                        fiveBills -= 3
                    else:
                        return False
                    
        return True