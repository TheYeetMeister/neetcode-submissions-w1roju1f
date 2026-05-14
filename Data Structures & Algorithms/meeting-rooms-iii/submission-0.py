class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        roomUse = [0 for _ in range(n)]
        meetings.sort()

        openMinHeap = [i for i in range(n)]
        heapq.heapify(openMinHeap)

        waitMinHeap = []

        resCnt = 0
        resRoom = 0

        for interval in meetings:
            while waitMinHeap and interval[0] >= waitMinHeap[0][0]:
                heapq.heappush(openMinHeap, waitMinHeap[0][1])
                heapq.heappop(waitMinHeap)

            newStart = interval[0]
            dist = interval[1] - interval[0]
            if not openMinHeap:
                newStart = waitMinHeap[0][0]
                heapq.heappush(openMinHeap, waitMinHeap[0][1])
                heapq.heappop(waitMinHeap)

            chosenRoom = heapq.heappop(openMinHeap)
            roomUse[chosenRoom] += 1
            if (roomUse[chosenRoom] > resCnt or 
            roomUse[chosenRoom] == resCnt and chosenRoom < resRoom):
                resRoom = chosenRoom
                resCnt = roomUse[chosenRoom]

            heapq.heappush(waitMinHeap, [newStart + dist, chosenRoom])

        return resRoom

            