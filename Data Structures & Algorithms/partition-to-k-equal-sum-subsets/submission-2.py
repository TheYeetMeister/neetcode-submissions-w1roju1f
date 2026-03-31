class Solution:
    def subsetsEqual(self, subsetSums: List[int]) -> bool:
        for i in range(1, len(subsetSums)):
            if subsetSums[i - 1] != subsetSums[i]:
                return False

        return True

    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        listSum = sum(nums)
        nums.sort(reverse = True)
        
        usedList = [False for _ in range(len(nums))]
        targetValue = listSum / k

        def dfs(i: int, k: int, subsetSum: int):
            if k == 0:
                return True
            if subsetSum == targetValue:
                return dfs(0, k - 1, 0)
            
            for j in range(i, len(nums)):
                if usedList[j] or subsetSum + nums[j] > targetValue:
                    continue
                usedList[j] = True
                if dfs(j + 1, k, subsetSum + nums[j]):
                    return True
                usedList[j] = False
            return False

        return dfs(0, k, 0)
        
        