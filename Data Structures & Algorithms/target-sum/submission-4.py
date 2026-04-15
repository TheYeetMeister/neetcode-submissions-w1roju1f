class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        def dfs(i, currSum):
            if i == len(nums):
                return 1 if target == currSum else 0

            return (dfs(i + 1, currSum + nums[i]) +
                    dfs(i + 1, currSum - nums[i]))

        return dfs(0, 0)