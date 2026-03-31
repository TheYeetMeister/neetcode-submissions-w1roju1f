class DSU:
    def __init__(self, n):
        self._parents = [i for i in range(n)]
        self._rank = [0 for _ in range(n)]

    def find(self, i):
        if self._parents[i] == i:
            return i

        self._parents[i] = self.find(self._parents[i])

        return self._parents[i]

    def union(self, i, j):
        rootI = self.find(i)
        rootJ = self.find(j)

        if rootI == rootJ:
            return False

        if self._rank[rootI] < self._rank[rootJ]:
            self._parents[rootI] = rootJ
        elif self._rank[rootI] > self._rank[rootJ]:
            self._parents[rootJ] = rootI
        else:
            self._parents[rootI] = rootJ;
            self._rank[rootJ] += 1

        return True 

        

class Solution:
    def calPtDistance(self, ptA: List[int], ptB: List[int]):
        return abs(ptA[0] - ptB[0]) + abs(ptA[1] -ptB[1])

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        firstPt = points[0]

        cost = 0

        minHeap = []
        groups = len(points);
        unionFind = DSU(groups)

        for i in range(len(points)):
            for j in range(len(points)):
                if i == j:
                    continue

                heapq.heappush(minHeap, (self.calPtDistance(points[i], points[j]), i, j))

        while groups > 1:
            edgeCost, i, j = heapq.heappop(minHeap)

            if unionFind.union(i, j):
                cost += edgeCost
                groups -= 1

        return cost