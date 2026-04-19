class SegmentTree:
    
    def __init__(self, nums: List[int]):
        self.nums = nums
    
    def update(self, index: int, val: int) -> None:
        self.nums[index] = val
    
    def query(self, L: int, R: int) -> int:
        currSum = 0

        for i in range(L, R + 1):
            currSum += self.nums[i]

        return currSum
