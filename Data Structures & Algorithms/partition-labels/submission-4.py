class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        lastInd = [-1 for _ in range(26)]

        for i in range(n):
            index = ord(s[i]) - ord('a')
            lastInd[index] = i

        size = end = 0
        res = []
        for i in range(n):
            size += 1
            newEnd = lastInd[ord(s[i]) - ord('a')]
            end = max(end, newEnd)

            if i == end:
                res.append(size)
                size = end = 0
        return res