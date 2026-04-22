class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        numsPad = [1]
        numsPad.extend(nums)
        numsPad.append(1)

        n = len(numsPad)
        dp = [[0 for _ in range(n)] for _ in range(n)]

        def dfs(left, right):
            if left > right:
               return 0 
            elif left == right:
                return numsPad[left - 1] * numsPad[left] * numsPad[left + 1]
            elif dp[left][right] > 0:
                return dp[left][right]

            maxValue = 0
            for value in range(left, right + 1):
                leftSide = dfs(left, value - 1)
                rightSide = dfs(value + 1, right)

                popValue = numsPad[left - 1] * numsPad[value] * numsPad[right + 1]
                maxValue = max(popValue + leftSide + rightSide, maxValue)

            dp[left][right] = maxValue
            return dp[left][right]

        return dfs(1, len(numsPad) - 2)
                    
