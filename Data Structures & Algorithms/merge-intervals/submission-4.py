class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        intervals.sort()
        intervalStart = intervals[0][0]
        intervalEnd = intervals[0][1]

        for i in range(1, len(intervals)):
            currInterval = intervals[i]

            if currInterval[0] > intervalEnd:
                res.append([intervalStart, intervalEnd])

                intervalStart = currInterval[0]
                intervalEnd = currInterval[1]
            else:
                intervalEnd = max(currInterval[1], intervalEnd)

        
        res.append([intervalStart, intervalEnd])

        return res