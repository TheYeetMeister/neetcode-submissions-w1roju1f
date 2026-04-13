class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dpNoCoin = [0 for _ in range(len(prices) + 2)]
        dpHasCoin = [0 for _ in range(len(prices) + 2)]

        for i in range(len(prices) - 1, -1, -1):
            dpNoCoin[i] = max(dpNoCoin[i + 1], dpHasCoin[i + 1] - prices[i])
            dpHasCoin[i] = max(dpHasCoin[i + 1], prices[i] + dpNoCoin[i + 2])


        return dpNoCoin[0]