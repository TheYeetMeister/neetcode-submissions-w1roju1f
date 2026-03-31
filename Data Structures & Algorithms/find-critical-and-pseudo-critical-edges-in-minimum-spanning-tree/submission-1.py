class DSU:
    def __init__(self, n):
        self._parent = [i for i in range(n)]
        self._rank = [0 for _ in range(n)]

    def find(self, i):
        if self._parent[i] == i:
            return i

        self._parent[i] = self.find(self._parent[i])
        return self._parent[i]

    def union(self, i, j):
        rootI = self.find(i)
        rootJ = self.find(j)

        if rootI == rootJ:
            return False

        if self._rank[rootI] > self._rank[rootJ]:
            self._parent[rootJ] = rootI
        elif self._rank[rootI] < self._rank[rootJ]:
            self._parent[rootI] = rootJ
        else:
            self._rank[rootI] += 1
            self._parent[rootJ] = rootI

        return True

class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        minHeap = []

        dsu = DSU(n)
        for i in range(len(edges)):
            heapq.heappush(minHeap, [edges[i][2], edges[i][0], edges[i][1], i])

        res = [[], []]
        groups = n
        while minHeap and n > 1:
            currCritical = []
            currWeight = minHeap[0][0]

            while minHeap and minHeap[0][0] == currWeight:
                wei, i, j, index = heapq.heappop(minHeap)

                if dsu.find(i) == dsu.find(j):
                    continue
                
                currCritical.append(index)

            size = 0
            nonNeededEdge = False
            for i in currCritical:
                if dsu.union(edges[i][0], edges[i][1]):
                    groups -= 1
                else:
                    nonNeededEdge = True

            if nonNeededEdge:
                res[1].extend(currCritical)
            else:
                res[0].extend(currCritical)

        return res