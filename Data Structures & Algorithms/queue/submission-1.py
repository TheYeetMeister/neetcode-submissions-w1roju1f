class Deque:
    def __init__(self):
        self._capacity = 1
        self._inner_list = [0]
        self._size = 0
        self._begin = 0
        self._end = 0

    def _resize(self):
        newCap = self._capacity * 2
        newList = [0 for _ in range(newCap)]

        for i in range(self._size):
            newList[i] = self._inner_list[(self._begin + i) % self._capacity]
        
        self._begin = 0
        self._end = self._size
        self._inner_list = newList
        self._capacity = newCap

    def isEmpty(self) -> bool:
        return self._size == 0

    def append(self, value: int) -> None:
        if self._size == self._capacity:
            self._resize()

        if self._end == self._capacity:
            self._end = 0

        self._inner_list[self._end] = value
        self._end += 1

        self._size += 1

    def appendleft(self, value: int) -> None:
        if self._size == self._capacity:
            self._resize()

        if self._begin == 0:
            self._begin = self._capacity
        
        self._begin -= 1
        self._inner_list[self._begin] = value
        self._size += 1


    def pop(self) -> int:
        if self.isEmpty():
            return -1

        if self._end == 0:
            self._end == self._capacity

        self._end -= 1
        self._size -= 1
        return self._inner_list[self._end]

    def popleft(self) -> int:
        if self.isEmpty():
            return -1
        
        returnVal = self._inner_list[self._begin]
        self._begin += 1
        self._size -= 1

        if self._begin == self._capacity:
            self._begin = 0

        return returnVal
