class disJointedUnion:
    def __init__(self, n: int):
        self._parent = [i for i in range(n)]
        self._rank = [0 for _ in range(n)]

    def find(self, i):
        if self._parent[i] == i:
            return i

        self._parent[i] = self.find(self._parent[i])
        return self._parent[i]

    def join(self, i, j) -> bool:
        root_i = self.find(i)
        root_j = self.find(j)

        if root_i == root_j:
            return False
        elif self._rank[root_i] < self._rank[root_j]:
            self._parent[root_i] = root_j
        elif self._parent[root_i] > self._rank[root_j]:
            self._parent[root_j] = root_i
        else:
            self._parent[root_j] = root_i
            self._rank[root_i] += 1

        return True


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        unionFind = disJointedUnion(len(edges) + 1)

        for i, j in edges:
            if not unionFind.join(i, j):
                return [i, j]

        return []