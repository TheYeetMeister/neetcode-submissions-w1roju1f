# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:
        n = len(pairs)

        if n <= 1:
            return pairs

        a = self.mergeSort(pairs[: n // 2])
        b = self.mergeSort(pairs[n // 2:])

        i = 0
        j = 0

        c = []
        while i < len(a) and j < len(b):
            if b[j].key < a[i].key:
                c.append(b[j])
                j += 1
            else:
                c.append(a[i])
                i += 1

        if i < len(a):
            c.extend(a[i:])
        else:
            c.extend(b[j:])

        return c
        



