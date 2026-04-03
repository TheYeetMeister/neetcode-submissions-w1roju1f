class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        combinations = [0 for _ in range(target + 1)]

        combinations[target] = 1

        for i in range(target - 1, -1, -1):
            for val in nums:
                if i + val > target:
                    continue

                combinations[i] += combinations[i + val]

        return combinations[0] 