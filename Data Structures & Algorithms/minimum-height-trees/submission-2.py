class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]

        for i, j in edges:
            adj[i].append(j)
            adj[j].append(i)
        
        def dfs(prev, i):
            minHeight = 0
            for j in adj[i]:
                if j == prev:
                    continue
                
                minHeight = max(1 + dfs(i, j), minHeight)

            return minHeight
        
        heights = []
        minHeight = float("inf")
        res = []

        for i in range(n):
            heights.append(dfs(-1, i))
            minHeight = min(minHeight, heights[-1])

        for i in range(n):
            if heights[i] == minHeight:
                res.append(i)
        
        return res
                
