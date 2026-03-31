class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        for index, n in enumerate(tasks):
            n.append(index)

        tasks.sort()
        print(tasks)

        time: int = 0
        i: int = 0
        minHeap = []
        res = []

        while i < len(tasks) or minHeap:
            while i < len(tasks) and time >= tasks[i][0]:
                heapq.heappush(minHeap, [tasks[i][1], tasks[i][2]])
                i += 1
            
            if len(minHeap) == 0:
                time = tasks[i][0]
                heapq.heappush(minHeap, [tasks[i][1], tasks[i][2]])
                i += 1

            task = heapq.heappop(minHeap)
            time += task[0]
            res.append(task[1])

        return res