class Solution:

    def combine(self, n: int, k: int) -> List[List[int]]:
        res: List[List[int]] = []
        subset: List[int] = []

        def dfs(start: int, n: int, k: int):
            if k == 0:
                res.append(subset.copy())
                return

            for i in range(start, n - k + 1):
                subset.append(i + 1)
                dfs(i + 1, n, k - 1)
                subset.pop()

        dfs(0, n, k)

        return res