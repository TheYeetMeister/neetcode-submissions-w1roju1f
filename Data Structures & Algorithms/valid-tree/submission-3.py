class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        nei = defaultdict(list)

        for i, j in edges:
            nei[i].append(j)
            nei[j].append(i)

        visited = set()
        currVisited = set()
        def dfs(prev, i):
            if i in currVisited:
                return False
            elif i in visited:
                return True

            visited.add(i)
            currVisited.add(i)

            for j in nei[i]:
                if j == prev:
                    continue
                
                if not dfs(i, j):
                    return False
            
            currVisited.remove(i)
            return True

        return dfs(-1, 0) and len(visited) == n
