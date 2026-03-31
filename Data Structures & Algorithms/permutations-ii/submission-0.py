class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        counter = Counter(nums)
        res = []

        def dfs(subset: List[int]):
            if len(subset) == len(nums):
                res.append(subset.copy())
                return

            for key, value in counter.items():
                if value > 0:
                    subset.append(key)
                    counter[key] -= 1
                    dfs(subset)
                    counter[key] += 1
                    subset.pop()
            
        dfs([])

        return res
            


