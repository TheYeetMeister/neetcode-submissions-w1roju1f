class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        taskCnt: list[int] = [0 for _ in range(26)]

        for task in tasks:
            taskCnt[ord(task) - ord('A')] += 1
        

        maxHeap: list[list[int, char]] = []
        remainingTasks = 0

        for i in range(26):
            if taskCnt[i] > 0:
                remainingTasks += 1
                heapq.heappush_max(maxHeap, [taskCnt[i], chr(ord('A') + i)])
        de: deque = deque([None for i in range(n)])

        count: int = 0

        while remainingTasks > 0:
            count += 1

            value = None

            if len(maxHeap) > 0:
                value = heapq.heappop_max(maxHeap)
                value[0] -= 1
            
            if value == None:
                de.append(None)
            elif value[0] > 0:
                de.append(value)
            else:
                remainingTasks -= 1
                de.append(None)

            newActive = de.popleft()

            if newActive != None:
                heapq.heappush_max(maxHeap, newActive)

        return count
        