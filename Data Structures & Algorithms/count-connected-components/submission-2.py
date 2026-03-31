class DisjointedUnion:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0 for _ in range(n)]

    def find(self, vertex) -> int:
        if self.parent[vertex] == vertex:
            return vertex

        self.parent[vertex] = self.find(self.parent[vertex])
        return self.parent[vertex]

    def join(self, i: int, j: int):
        rootI = self.find(i)
        rootJ = self.find(j)

        if rootI != rootJ:
            if self.rank[rootI] < self.rank[rootJ]:
                self.parent[rootI] = rootJ
            elif self.rank[rootI] > self.rank[rootJ]:
                self.parent[rootJ] = rootI
            else:
                self.parent[rootI] = rootJ
                self.rank[rootJ] += 1

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        unionFind = DisjointedUnion(n)

        for i, j in edges:
            unionFind.join(i, j)

        cnt = 0
        parentsFound = set()
        for i in range(n):
            parent = unionFind.find(i)

            if not parent in parentsFound:
                cnt += 1
                parentsFound.add(parent)

        return cnt