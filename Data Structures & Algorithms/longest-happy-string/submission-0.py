class Solution:
    def addLetterCount(self, maxHeap: List[int], letter: char, num: int):
        if num > 0:
            heapq.heappush_max(maxHeap, [num, letter])

    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        res :str = ""
        maxHeap: List[int] = []

        self.addLetterCount(maxHeap, 'a', a)
        self.addLetterCount(maxHeap, 'b', b)
        self.addLetterCount(maxHeap, 'c', c)

        prevHold = None
        prevCnt = 0
        
        while maxHeap:
            temp: List[int] = heapq.heappop_max(maxHeap)
            if prevHold != temp:
                if prevCnt == 2 and prevHold[0] > 0:
                    heapq.heappush_max(maxHeap, prevHold)
                    
                prevCnt = 1
            else:
                prevCnt += 1

            prevHold = temp
            prevHold[0] -= 1
            res += prevHold[1]

            if prevHold[0] > 0:
                if prevCnt != 2:
                    heapq.heappush_max(maxHeap, prevHold)


        return res


        