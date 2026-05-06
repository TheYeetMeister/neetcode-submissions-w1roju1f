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

        beginning = -1
        end = -1
        res = []
        for i in range(n):
            newBeg, newEnd = ranges[ord(s[i]) - ord('a')]
            if end == -1:
                beginning, end = newBeg, newEnd
            else:
                end = max(end, newEnd)

            if i == end:
                res.append(end - beginning + 1)
                beginning, end = -1, -1
        return res