class Solution:
    def jump(self, nums: List[int]) -> int:
        maxLeapDist = 0
        currLeaps = 0
        leapCutOff = 0
        n = len(nums)

        for i in range(n - 1):
            maxLeapDist = max(i + nums[i], maxLeapDist)
            if i == leapCutOff:
                currLeaps += 1
                leapCutOff = maxLeapDist
        
        
        return currLeaps
        

