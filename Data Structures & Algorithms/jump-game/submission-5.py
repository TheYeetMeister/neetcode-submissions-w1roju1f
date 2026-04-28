class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxIndex = 0
        i = 0

        while i <= len(nums) and i <= maxIndex:
            maxIndex = max(i + nums[i], maxIndex)
            if maxIndex >= len(nums) - 1:
                return True

            i += 1
        
        return False