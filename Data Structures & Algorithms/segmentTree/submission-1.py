class SegmentTree:
    
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.prefixTree = [0]

        for i in nums:
            self.prefixTree.append(self.prefixTree[-1] + i)
    
    def update(self, index: int, val: int) -> None:
        diff = val - self.nums[index]
        self.nums[index] = val

        for i in range(index + 1, len(self.nums) + 1):
            self.prefixTree[i] += diff
    
    def query(self, L: int, R: int) -> int:
        return self.prefixTree[R + 1] - self.prefixTree[L]
