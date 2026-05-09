class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        start = 0
        end = 0
        n = len(intervals)

        while start < n and intervals[start][1] < newInterval[0]:
            start += 1

        end = start

        while end < n and intervals[end][1] < newInterval[1]:
            end += 1

        if start < n and intervals[start][1] >= newInterval[0]:
            newInterval[0] = min(newInterval[0], intervals[start][0])

        if end < n and intervals[end][0] <= newInterval[1]:
            newInterval[1] = max(newInterval[1], intervals[end][1])

        res = []

        i = 0
        while i < n and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1
        
        res.append(newInterval)
        while i < n:
            if intervals[i][0] > newInterval[1]:
                res.append(intervals[i])
            i += 1

        return res

        