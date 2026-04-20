# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def insertionSort(self, pairs: List[Pair]) -> List[List[Pair]]:
        res = []

        n = len(pairs)
        for i in range(n):
            currPair = pairs[i]
            
            j = 0
            while j < i and pairs[j].key <= pairs[i].key:
                j += 1
            
            while j < i + 1:
                temp = pairs[j]
                pairs[j] = currPair
                currPair = temp

                j += 1
                
            res.append(pairs[:])

        return res
