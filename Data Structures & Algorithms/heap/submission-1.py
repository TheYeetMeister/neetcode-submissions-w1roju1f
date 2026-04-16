class MinHeap:
    def __init__(self):
        self.buf = []

    def heapifyUp(self, currIndex):
        while currIndex > 0:
            parent = (currIndex - 1) // 2
            if self.buf[currIndex] < self.buf[parent]:
                self.buf[currIndex], self.buf[parent] = self.buf[parent], self.buf[currIndex]
                currIndex = parent
            else:
                break
    
    def heapifyDown(self, currIndex):
        while True:
            left = currIndex * 2 + 1
            right = currIndex * 2 + 2
            smallestIndex = currIndex

            if left < len(self.buf) and self.buf[left] < self.buf[smallestIndex]:
                smallestIndex = left
            if right < len(self.buf) and self.buf[right] < self.buf[smallestIndex]:
                smallestIndex = right

            if smallestIndex != currIndex:
                self.buf[currIndex], self.buf[smallestIndex] = self.buf[smallestIndex], self.buf[currIndex]
                currIndex = smallestIndex
            else:
                break

    def push(self, val: int) -> None:
        self.buf.append(val)
        self.heapifyUp(len(self.buf) - 1)

    def pop(self) -> int:
        if not self.buf:
            return -1
        elif len(self.buf) == 1:
            return self.buf.pop()

        minVal = self.buf[0]
        self.buf[0] = self.buf.pop()
        self.heapifyDown(0)
        return minVal

    def top(self) -> int:
        return -1 if not self.buf else self.buf[0]    

    def heapify(self, nums: List[int]) -> None:
        self.buf = [i for i in nums]

        n = len(self.buf)

        for i in range(n - 1, -1, -1):
            self.heapifyDown(i)
        
        