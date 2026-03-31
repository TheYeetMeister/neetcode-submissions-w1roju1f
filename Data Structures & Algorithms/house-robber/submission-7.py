class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        money = [float("infinity") for _ in range(n + 1)]

        money[n] = 0
        money[n - 1] = nums[n - 1]

        for i in range(n - 2, -1, -1):
            take = money[i + 2] + nums[i]
            noTake = money[i + 1]

            money[i] = max(take, noTake)
        
        return money[0]