class CountSquares:
    def __init__(self):
        self._dict = {}

    def add(self, point: List[int]) -> None:
        internalTuple = (point[0], point[1])
        self._dict[internalTuple] = self._dict.get(internalTuple, 0) + 1

    def count(self, point: List[int]) -> int:
        cnt = 0
        for i, j in self._dict.keys():
            maxAdd = 0
            if (
                (abs(point[0] - i) != 0 and abs(point[0] - i) == abs(point[1] - j)) and
                (point[0], j) in self._dict and (i, point[1]) in self._dict
            ):
                cnt += (
                    self._dict[(i, j)] *
                    self._dict[(point[0], j)] *
                    self._dict[(i, point[1])]
                )

        return cnt
