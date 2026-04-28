class Solution:
    def topologicalSort(self, n: int, edges: List[List[int]]) -> List[int]:
        ordering = []
        indegree = [0 for _ in range(n)]

        adj = defaultdict(list)

        for u, v in edges:
            adj[u].append(v)
            indegree[v] += 1

        def dfs(u):
            if indegree[u] != 0:
                return
            
            indegree[u] -= 1
            ordering.append(u)

            for v in adj[u]:
                indegree[v] -= 1
                dfs(v)

        for i in range(n):
            dfs(i)

        return [] if len(ordering) != n else ordering