class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        value = n

        for i in range(n):
            value ^= i
            value ^= nums[i]

        return value