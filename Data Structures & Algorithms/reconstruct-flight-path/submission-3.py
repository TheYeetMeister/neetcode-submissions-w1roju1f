class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = defaultdict(list)
        edges = len(tickets)
        res = ["JFK"]

        tickets.sort()
        for i, j in tickets:
            adj[i].append([j, False])

        def dfs(airport: str):
            if len(res) - 1 == edges:
                return True

            for i in range(len(adj[airport])):
                content = adj[airport][i]
                if content[1]:
                    continue
                
                res.append(content[0])
                content[1] = True

                if dfs(content[0]):
                    return True
                
                content[1] = False
                res.pop()

            return False

        dfs("JFK")

        return res