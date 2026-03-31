class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = float('-inf')
        for i in range(len(nums)):
            currMul = 1
            for j in range(i, len(nums)):
                currMul *= nums[j]

                res = max(res, currMul)

        return res