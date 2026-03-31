class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        boolList = [True for _ in range(len(nums))]
        subset = []
        res = []

        def dfs():
            if len(subset) == len(nums):
                res.append(subset.copy())
                return

            for j in range(len(nums)):
                if boolList[j]:
                    boolList[j] = False
                    subset.append(nums[j])
                    dfs()
                    subset.pop()
                    boolList[j] = True

        dfs()
        return res
        