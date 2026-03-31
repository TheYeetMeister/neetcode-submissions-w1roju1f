class Solution:
    def dfs(self, nums: List[int], i: int):
        if (i == len(nums)):
            self.res.append([i for i in self.subset])
            return

        self.subset.append(nums[i])
        self.dfs(nums, i + 1)
        self.subset.pop()

        self.dfs(nums, i + 1)
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res: List[List[int]] = []
        self.subset: List[int] = []

        self.dfs(nums, 0)

        return self.res

        