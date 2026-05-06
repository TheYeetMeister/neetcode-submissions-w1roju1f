class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        ranges = [-1 for _ in range(26)]

        for i in range(n):
            index = ord(s[i]) - ord('a')

            if ranges[index] == -1:
                ranges[index] = [i, i]
            else:
                ranges[index][1] = i

        minHeap = []

        for i in ranges:
            if i != -1:
                heapq.heappush(minHeap, i)

        beginning, end = heapq.heappop(minHeap)
        res = []

        while minHeap:
            newBeg, newEnd = heapq.heappop(minHeap)

            if newBeg < end:
                end = max(newEnd, end)
            else:
                res.append(end - beginning + 1)
                beginning, end = newBeg, newEnd

        res.append(end - beginning + 1)
        return res