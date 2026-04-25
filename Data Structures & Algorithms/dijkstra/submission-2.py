class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], src: int) -> Dict[int, int]:
        minHeap = []

        smallest = {}
        for i in range(n):
            smallest[i] = -1

        smallest[src] = 0

        adj = defaultdict(list)

        for i, j, w in edges:
            adj[i].append((j, w))

        for nei, weight in adj[src]:
            heapq.heappush(minHeap, (weight, nei))
        
        while minHeap:
            weight, node = heapq.heappop(minHeap)

            if smallest[node] != -1:
                continue

            smallest[node] = weight

            for nei, pathWeight in adj[node]:
                if smallest[nei] == -1:
                    heapq.heappush(minHeap, (weight + pathWeight, nei))
        
        return smallest
        