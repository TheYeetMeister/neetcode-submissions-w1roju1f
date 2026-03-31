class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        minHeap: List[int] = nums[:k]
        heapq.heapify(minHeap)

        for i in range(k, len(nums)):
            heapq.heappush(minHeap, nums[i])
            heapq.heappop(minHeap)
        
        return minHeap[0]