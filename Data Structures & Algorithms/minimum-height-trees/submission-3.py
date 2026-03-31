class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]

        adj = [[] for _ in range(n)]
        for i, j, in edges:
            adj[i].append(j)
            adj[j].append(i)

        edge_cnt = [0 for _ in range(n)]
        leaves = deque()

        for i in range(n):
            edge_cnt[i] = len(adj[i])
            if len(adj[i]) == 1:
                leaves.append(i)

        while leaves:
            if n <= 2:
                return list(leaves)
            for _ in range(len(leaves)):
                node = leaves.popleft()
                n -= 1
                for nei in adj[node]:
                    edge_cnt[nei] -= 1
                    if edge_cnt[nei] == 1:
                        leaves.append(nei)
                
