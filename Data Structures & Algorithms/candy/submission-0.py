class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 1:
            return 1

        res = [0 for i in range(n)]
        adj = defaultdict(list)
        for i in range(n):
            if i - 1 >= 0 and ratings[i] < ratings[i - 1]:
                adj[i].append(i - 1)

            if i + 1 < n and ratings[i] < ratings[i + 1]:
                adj[i].append(i + 1)
            
            if ((i - 1 < 0 or ratings[i] <= ratings[i - 1]) and
                (i + 1 >= n or ratings[i] <= ratings[i + 1])):
                res[i] = 1

        def dfs(i):
            for nei in adj[i]:
                res[nei] = max(res[i] + 1, res[nei])
                dfs(nei)
        
        for i in range(n):
            if res[i] == 1:
                dfs(i)

        return sum(res)