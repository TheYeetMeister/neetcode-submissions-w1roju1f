class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [False for _ in range(len(nums))]
        dp[-1] = True

        for i in range(len(nums) - 2, -1, -1):
            for j in range(0, nums[i]):
                if j + i + 1 == len(nums):
                    break

                dp[i] = dp[i] or dp[i + j + 1]

        return dp[0]