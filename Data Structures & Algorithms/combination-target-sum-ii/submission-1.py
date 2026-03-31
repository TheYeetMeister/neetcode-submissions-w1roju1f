class Solution:
    def dfs(self, i: int, currSum: int, candidates: List[int], target: int) -> List[List[int]]:
        if currSum == target:
            self.res.append(self.subSet.copy())
            return

        if i == len(candidates) or currSum > target:
            return

        nextI = i + 1
        while nextI < len(candidates) and candidates[i] == candidates[nextI]:
            nextI += 1
        
        self.dfs(nextI, currSum,candidates, target)
        for j in range(i, nextI):
            currSum += candidates[i]
            self.subSet.append(candidates[i])
            self.dfs(nextI, currSum, candidates, target)

        for j in range(i, nextI):
            self.subSet.pop()

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.res = []
        self.subSet = []

        self.dfs(0, 0, candidates, target)

        return self.res