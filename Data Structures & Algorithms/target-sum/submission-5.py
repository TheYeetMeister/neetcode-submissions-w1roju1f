class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        values = {}
        def dfs(i, currSum):
            if (i, currSum) in values:
                return values[(i, currSum)]

            if i == len(nums):
                return 1 if target == currSum else 0

            values[(i, currSum)] = (dfs(i + 1, currSum + nums[i]) +
                    dfs(i + 1, currSum - nums[i]))
            return values[(i, currSum)]

        return dfs(0, 0)