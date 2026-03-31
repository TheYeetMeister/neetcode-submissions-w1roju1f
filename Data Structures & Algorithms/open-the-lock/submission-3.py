class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadVals = set()
        for deadend in deadends:
            deadVals.add(deadend)
            
        target = target

        directions = [1, -1]

        visited = set()

        queue = deque()
        queue.append("0000")
        steps = 0

        while queue:
            size = len(queue)

            for _ in range(size):
                currCode = queue.popleft()

                if currCode == target:
                    return steps

                if currCode in deadVals or currCode in visited:
                    continue
                visited.add(currCode)

                for i in range(len(currCode)):
                    for direc in directions:
                        newChar = ord(currCode[i]) + direc

                        if newChar > ord("9"):
                            newChar = ord("0")
                        elif newChar < ord("0"):
                            newChar = ord("9")
                        
                        stepCode = currCode[:i] + chr(newChar) + currCode[i + 1:]

                        queue.append(stepCode)
                
            steps += 1

        return -1