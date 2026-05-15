class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort(key=lambda x:(x[0], x[1] - x[0]))
        sortedQuer = sorted(queries)
        shortestQuery = {}
        minHeap = []

        i = 0
        for query in sortedQuer:
            while i < len(intervals) and intervals[i][0] <= query:
                start = intervals[i][0] 
                end = intervals[i][1]
                heapq.heappush(minHeap, [end - start + 1, end])
                i += 1
            
            while minHeap and minHeap[0][1] < query:
                heapq.heappop(minHeap)

            if not minHeap:
                shortestQuery[query] = -1
            else:
                shortestQuery[query] = minHeap[0][0]

        n = len(queries)
        res = [0] * n
        for i in range(n):
            queryVal = queries[i]
            res[i] = shortestQuery[queryVal]

        return res