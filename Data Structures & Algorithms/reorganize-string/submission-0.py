from string import ascii_lowercase

class Solution:
    def createFrequencyList(self, s: str) -> dict:
        frequencyList: dict = defaultdict(lambda: 0)

        for char in s:
            frequencyList[char] += 1
        
        return frequencyList

    def reorganizeString(self, s: str) -> str:
        frequencyList = self.createFrequencyList(s)
        maxHeap: list[list[int, char]] = []

        for letter in ascii_lowercase:
            if frequencyList[letter] > 0:
                heapq.heappush_max(maxHeap, [frequencyList[letter], letter])

        prevInfo = None
        res: str = ""
        while maxHeap:
            letterInfo: list[int, char] = heapq.heappop_max(maxHeap)
            res += letterInfo[1]
            letterInfo[0] -= 1

            if prevInfo:
                heapq.heappush_max(maxHeap, prevInfo)

            prevInfo = letterInfo if (letterInfo[0] > 0) else None

        return res if (prevInfo == None) else ""
        