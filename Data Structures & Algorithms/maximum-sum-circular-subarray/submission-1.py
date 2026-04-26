class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        maxAmt = float("-inf")
        n = len(nums)


        for i in range(n):
            currAmt = float("-inf")

            for j in range(i, n + i):
                currAmt += nums[j % n]

                if currAmt < nums[j % n]:
                    currAmt = nums[j % n]

                maxAmt = max(maxAmt, currAmt)

        return maxAmt