class Solution:
    def maximumProfit(self, profit: List[int], weight: List[int], capacity: int) -> int:
        values = [-1 for _ in range(capacity + 1)]
        values[0] = 0

        for i in range(len(weight)):
            currWeight = weight[i]
            currProfit = profit[i]

            for j in range(capacity - currWeight + 1):
                if values[j] != -1:
                    values[j + currWeight] = max(values[j] + currProfit, values[j + currWeight])
        
        return max(values)