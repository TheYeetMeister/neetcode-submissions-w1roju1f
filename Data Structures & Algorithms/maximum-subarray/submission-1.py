class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = float("-inf")
        currSum = float("-inf")

        for i in nums:
            currSum += i

            if currSum < i:
                currSum = i

            maxSum = max(currSum, maxSum)
        
        return maxSum
        