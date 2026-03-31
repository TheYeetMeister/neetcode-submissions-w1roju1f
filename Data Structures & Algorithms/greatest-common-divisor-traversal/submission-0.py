class UnionFind:
    def __init__(self, n):
        self._parent = [i for i in range(n)]
        self._rank = [0 for _ in range(n)]

    def find(self, i):
        if i == self._parent[i]:
            return i

        self._parent[i] = self.find(self._parent[i])
        return self._parent[i]

    def union(self, i, j):
        rootI = self.find(i)
        rootJ = self.find(j)

        if rootI == rootJ:
            return

        if self._rank[rootI] > self._rank[rootJ]:
            self._parent[rootJ] = rootI
        elif self._rank[rootI] < self._rank[rootJ]:
            self._parent[rootI] = rootJ
        else:
            self._rank[rootI] += 1
            self._parent[rootJ] = rootI
        


class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        def GCD(i, j):
            minNum = min(i, j)
            maxNum = max(i, j)

            for k in range(minNum, 1, -1):
                if minNum % k == 0 and maxNum % k == 0:
                    return True

            return False

        n = len(nums)
        DSU = UnionFind(n)

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                rootI = DSU.find(i)
                rootJ = DSU.find(j)

                if rootI == rootJ:
                    continue
                
                if GCD(nums[i], nums[j]):
                    DSU.union(i, j)
                    n -= 1
        
        return n == 1



