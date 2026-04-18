class UnionFind:
    
    def __init__(self, n: int):
        self._parent = [i for i in range(n)]
        self._rank = [0 for _ in range(n)]
        self._sets = n

    def find(self, x: int) -> int:
        if self._parent[x] == x:
            return x

        self._parent[x] = self.find(self._parent[x])
        return self._parent[x]

    def isSameComponent(self, x: int, y: int) -> bool:
        rootX = self.find(x)
        rootY = self.find(y)

        return rootX == rootY

    def union(self, x: int, y: int) -> bool:
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
        
        self._sets -= 1
        return True

    def getNumComponents(self) -> int:
        return self._sets
