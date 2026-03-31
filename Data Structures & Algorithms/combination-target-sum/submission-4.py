class Solution:
    def backtracking(self, i: int, currSum: int, nums: List[int], target: int):
        if currSum == target:
            self.res.append(self.subset.copy())
            return

        if i == len(nums) or currSum > target:
            return

        count: int = 0
        while currSum <= target:
            self.backtracking(i + 1, currSum, nums, target)
            currSum += nums[i]
            self.subset.append(nums[i])

            count += 1

        for i in range(count):
            self.subset.pop()

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()

        self.res = []
        self.subset = []

        self.backtracking(0, 0, nums, target)

        return self.res