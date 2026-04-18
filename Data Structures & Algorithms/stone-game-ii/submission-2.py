class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = {}

        def dfs(piles, i, m, aliceTurn):
            if (i, m, aliceTurn) in dp:
                return dp[(i, m, aliceTurn)]

            pileGrab = 0
            res = 0 if aliceTurn else float("inf")

            for j in range(i, min(n, i + 2 * m)):
                pileGrab += piles[j]
                newRes = dfs(piles, j + 1, max(j - i + 1, m), not aliceTurn)

                if aliceTurn:
                    res = max(res, newRes + pileGrab)
                else:
                    res = min(res, newRes)
            
            dp[(i, m, aliceTurn)] = res if res != float("inf") else 0
            return dp[(i, m, aliceTurn)]
        
        return dfs(piles, 0, 1, True)