class Solution:
    def maximumProfit(self, profit: List[int], weight: List[int], capacity: int) -> int:
        weightList = [-1 for _ in range(capacity + 1)]
        weightList[0] = 0

        n = len(profit)
        for i in range(n):
            currProfit = profit[i]
            currWeight = weight[i]

            for j in range(capacity - currWeight, -1, -1):
                if weightList[j] != -1:
                    weightList[j + currWeight] = max(weightList[j] + currProfit, weightList[j + currWeight])


        return max(weightList)

