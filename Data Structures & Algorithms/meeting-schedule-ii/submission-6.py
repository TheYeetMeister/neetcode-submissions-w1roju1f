"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals.sort(key=lambda x: (x.start, x.end))
        res = 0
        minHeap = []

        for inter in intervals:
            while minHeap and minHeap[0] <= inter.start:
                heapq.heappop(minHeap)

            heapq.heappush(minHeap, inter.end)

            res = max(res, len(minHeap))

        return res