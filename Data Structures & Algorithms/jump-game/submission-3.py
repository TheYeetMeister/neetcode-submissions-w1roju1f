class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [False for _ in range(len(nums))]
        dp[-1] = True

        for i in range(len(nums) - 2, -1, -1):
            for j in range(nums[i]):
                if dp[i + j + 1]:
                    dp[i] = True
                    break

        return dp[0]