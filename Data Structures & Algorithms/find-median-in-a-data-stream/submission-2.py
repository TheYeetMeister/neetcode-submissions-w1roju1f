class MedianFinder:

    def __init__(self):
        self.rightMinHeap = []
        self.leftMaxHeap = []
        
    def size(self):
        return len(self.rightMinHeap) + len(self.leftMaxHeap)
    
    def isLeftMaxHeapLarger(self):
        return len(self.rightMinHeap) < len(self.leftMaxHeap)

    def isRightMinHeapLarger(self):
        return len(self.rightMinHeap) > len(self.leftMaxHeap)
    
    def addNum(self, num: int) -> None:
        median: float = self.findMedian()

        if num > median:
            if self.isRightMinHeapLarger():
                heapq.heappush_max(
                    self.leftMaxHeap, 
                    heapq.heappop(self.rightMinHeap)
                )
            
            heapq.heappush(self.rightMinHeap, num)
        else:
            if self.isLeftMaxHeapLarger():
                heapq.heappush(
                    self.rightMinHeap,
                    heapq.heappop_max(self.leftMaxHeap)
                )
            
            heapq.heappush_max(self.leftMaxHeap, num)
        
    def findMedian(self) -> float:
        if self.size() == 0:
            return 0 
        elif self.size() % 2 == 0:
            return (self.rightMinHeap[0] + self.leftMaxHeap[0]) / 2
        elif self.isLeftMaxHeapLarger():
            return self.leftMaxHeap[0]
        else:
            return self.rightMinHeap[0]

        
        