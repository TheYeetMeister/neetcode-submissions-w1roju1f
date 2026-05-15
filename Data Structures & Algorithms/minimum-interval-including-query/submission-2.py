class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort(key=lambda x:(x[0], x[1]))

        shortestQuery = {}

        for inter in intervals:
            start = inter[0]
            end = inter[1]
            length = end - start + 1

            for i in range(start, end + 1):
                if i not in shortestQuery or shortestQuery[i] > length:
                    shortestQuery[i] = length

        n = len(queries)
        res = [0] * n
        for i in range(n):
            queryVal = queries[i]
            res[i] = -1 if queryVal not in shortestQuery else shortestQuery[queryVal]

        return res