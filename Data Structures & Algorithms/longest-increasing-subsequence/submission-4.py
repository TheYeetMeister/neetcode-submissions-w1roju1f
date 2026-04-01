class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = [1 for _ in range(len(nums))]
        maxRes = 1

        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[j] > nums[i]:
                    res[i] = max(res[i], 1 + res[j])
            
            maxRes = max(res[i], maxRes)

        return maxRes

