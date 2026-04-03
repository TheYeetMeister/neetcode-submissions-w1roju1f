class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        memoize = {}
        def dfs(currSum):
            if currSum in memoize:
                return memoize[currSum]
            elif currSum == target:
                return 1
            elif currSum > target:
                return 0

            returnVal = 0
            for i in nums:
                returnVal += dfs(currSum + i)
            
            memoize[currSum] = returnVal
            return returnVal

        return dfs(0)