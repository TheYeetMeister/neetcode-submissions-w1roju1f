class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        minHeap = []
        minHeapDestination = []

        for trip in trips:
            heapq.heappush(minHeap, [trip[1], trip[2], trip[0]])
        
        currTime = 0
        currSize = 0
        while minHeap:
            top = heapq.heappop(minHeap)
            currTime = top[0]
            currSize += top[2]

            heapq.heappush(minHeapDestination, [top[1], top[2]])
            
            while minHeapDestination and minHeapDestination[0][0] <= currTime:
                currSize -= heapq.heappop(minHeapDestination)[1]

            if currSize > capacity:
                return False

        return True