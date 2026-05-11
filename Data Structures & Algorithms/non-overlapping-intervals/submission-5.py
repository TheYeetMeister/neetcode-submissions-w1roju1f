class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()

        removed = set()
        def dfs(i, removed):
            if i == len(intervals):
                return 0

            removed.add(i)
            remCnt = 1 + dfs(i + 1, removed)
            removed.remove(i)

            overlap = False
            for j in range(i):
                if j in removed:
                    continue

                keptInt = intervals[j]
                if keptInt[1] > intervals[i][0]:
                    overlap = True
                    break

            if not overlap:
                remCnt = min(remCnt, dfs(i + 1, removed))
            
            return remCnt

        return dfs(0, removed)
