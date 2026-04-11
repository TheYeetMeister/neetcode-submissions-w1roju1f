class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        totalWeight = sum(stones)
        halfWeight = totalWeight // 2
        
        res = 0
        dp = set()
        dp.add(0)

        for i in stones:
            newDp = set()
            for num in dp:
                if i + num <= halfWeight:
                    newDp.add(i + num)
                    res = max(res, i + num)
            
            dp.update(newDp)


        return totalWeight - (2 * res)
                    