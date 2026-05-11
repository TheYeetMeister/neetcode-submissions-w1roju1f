class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: (x[1], x[0]))

        lastInt = intervals[0]
        remCnt = 0

        for i in range(1, len(intervals)):
            if intervals[i][0] < lastInt[1]:
                remCnt += 1
            else:
                lastInt = intervals[i]

        return remCnt
