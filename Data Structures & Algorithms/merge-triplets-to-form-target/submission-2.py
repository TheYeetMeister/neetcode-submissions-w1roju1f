class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        def isElemLarger(triplet):
            for i in range(3):
                if triplet[i] > target[i]:
                    return True

            return False

        resTriplet = [0, 0, 0]

        for trip in triplets:
            if isElemLarger(trip):
                continue

            for i in range(3):
                resTriplet[i] = max(resTriplet[i], trip[i])

        return resTriplet == target