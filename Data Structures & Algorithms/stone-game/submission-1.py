class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        piles.sort(reverse=True)

        sumScore = 0

        for i in range(len(piles)):
            if i % 2:
                sumScore -= piles[i]
            else:
                sumScore += piles[i]

        return sumScore > 0