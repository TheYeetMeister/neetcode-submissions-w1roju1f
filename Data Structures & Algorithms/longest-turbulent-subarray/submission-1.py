class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        length = 1
        res = 1
        prevGreaterThan = False

        for i in range(len(arr) - 1):
            if (prevGreaterThan and arr[i] > arr[i + 1] or
                not prevGreaterThan and arr[i] < arr[i + 1]):
                length += 1
            elif arr[i] == arr[i + 1]:
                length = 1
            else:
                length = 2
            
            prevGreaterThan = arr[i] < arr[i + 1]
            res = max(length, res)

        return res