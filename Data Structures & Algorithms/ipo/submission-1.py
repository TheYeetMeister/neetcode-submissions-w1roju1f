class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        minHeap = [[capital[i], profits[i]] for i in range(len(profits))]
        maxHeap = []

        heapq.heapify(minHeap)

        for _ in range(k):
            while minHeap and minHeap[0][0] <= w:
                heapq.heappush_max(
                    maxHeap,
                    heapq.heappop(minHeap)[1]
                )

            if maxHeap:
                w += heapq.heappop_max(maxHeap)
            else:
                return w
            
        return w

        