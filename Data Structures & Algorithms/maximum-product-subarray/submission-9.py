class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        conMax = nums[0]
        conMin = nums[0]

        resMax = nums[0]

        for i in range(1, len(nums)):
            currMin = min(nums[i] * conMax, nums[i] * conMin)
            currMax = max(nums[i] * conMax, nums[i] * conMin)

            conMin = min(currMin, nums[i])
            conMax = max(currMax, nums[i])

            resMax = max(conMax, resMax)

        return resMax
            