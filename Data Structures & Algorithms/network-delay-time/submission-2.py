class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        visited = set()

        time = 0

        adj = defaultdict(list)
        
        for src, target, time in times:
            adj[src].append([target, time])

        minHeap = [(0, k)]

        while minHeap:
            top = heapq.heappop(minHeap)
            node = top[1]
            timeTravel = top[0]

            if node in visited:
                continue
            
            time = timeTravel
            visited.add(node)

            for target, adjDist in adj[node]:
                if target in visited:
                    continue

                heapq.heappush(minHeap, (time + adjDist, target))

        print(visited)
        return time if len(visited) == n else -1

        