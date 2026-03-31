class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        res = [float("infinity") for _ in range(amount + 1)]
        res[0] = 0

        for i in range(amount):
            for j in coins:
                if i + j > amount:
                    continue

                res[i + j] = min(res[i + j], res[i] + 1)

        return res[amount] if res[amount] != float("infinity") else -1