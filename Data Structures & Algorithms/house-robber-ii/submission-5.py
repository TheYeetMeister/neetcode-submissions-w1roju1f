class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]

        def findMaxRobs(start, end):
            first = 0
            second = 0

            for i in range(start, end):
                temp = second
                second = max(nums[i] + first, second)
                first = temp
            
            return second

        return max(findMaxRobs(0, n - 1), findMaxRobs(1, n))


        