class Solution:
    def backtracking(self, beg: int, currNum: int, nums: List[int]):
        if beg == len(nums):
            self.total += currNum
            return
        
        self.backtracking(beg + 1, currNum ^ nums[beg], nums)
        self.backtracking(beg + 1, currNum, nums)


    def subsetXORSum(self, nums: List[int]) -> int:
        self.total = 0
        self.backtracking(0, 0, nums)
        return self.total