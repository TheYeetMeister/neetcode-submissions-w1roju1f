# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:

    def partion(self, pairs:List[Pair], left, right) -> int:
        pivot = pairs[right].key

        i: int = left - 1

        for j in range(left, right):
            if pairs[j].key < pivot:
                i += 1
                pairs[i], pairs[j] = pairs[j], pairs[i]

        pairs[i + 1], pairs[right] = pairs[right], pairs[i + 1]
        return i + 1

    def quicksortHelper(self, pairs: List[Pair], i, j):
        if i >= j:
            return

        split = self.partion(pairs, i, j)

        self.quicksortHelper(pairs, i, split - 1)
        self.quicksortHelper(pairs, split + 1, j)

    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        self.quicksortHelper(pairs, 0, len(pairs) - 1)

        return pairs
        