class DSU:
    def __init__(self, n):
        self._parent = [i for i in range(n)]
        self._rank = [0 for _ in range(n)]

    def find(self, i):
        if i == self._parent[i]:
            return i

        self._parent[i] = self.find(self._parent[i])
        return self._parent[i]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX == rootY:
            return False

        if self._rank[rootX] > self._rank[rootY]:
            self._parent[rootY] = rootX
        elif self._rank[rootX] < self._rank[rootY]:
            self._parent[rootX] = rootY
        else:
            self._rank[rootX] += 1
            self._parent[rootY] = rootX
        
        return True

class Solution:
    def minimumSpanningTree(self, n: int, edges: List[List[int]]) -> int:
        union = DSU(n)

        minHeap = []

        for u, v, w in edges:
            heapq.heappush(minHeap, (w, u, v))
        
        res = 0
        while minHeap and n != 1:
            weight, u, v = heapq.heappop(minHeap)

            if union.union(u, v):
                res += weight
                n -= 1


        return res if n == 1 else -1