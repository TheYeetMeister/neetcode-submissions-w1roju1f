class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target = sum(nums)

        if target % 2 == 1:
            return False
        
        target //= 2
        
        res = [[False for _ in range(target + 1)] for _ in range(len(nums) + 1)]

        res[0][0] = True
        for i in range(len(nums)):
            for j in range(target + 1):
                if res[i][j]:
                    res[i + 1][j] = True

                    if j + nums[i] <= target:
                        res[i + 1][j + nums[i]] = True

        return res[-1][-1]

