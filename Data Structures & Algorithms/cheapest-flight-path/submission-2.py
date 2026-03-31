class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = [[] for _ in range(n)]
        cost = [float("infinity") for _ in range(n)]
        cost[dst] = 0

        for i, j, price in flights:
            adj[j].append((i, price))

        que = deque([dst])

        while k + 1 > 0:
            size = len(que)

            for i in range(size):
                node = que.popleft()
                currCost = cost[node]

                for nei, price in adj[node]:
                    if currCost + price < cost[nei]:
                        cost[nei] = currCost + price
                        que.append(nei)


            k -= 1 

        return cost[src] if cost[src] != float("infinity") else -1