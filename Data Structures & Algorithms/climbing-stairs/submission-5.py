class Solution:
    def climbStairs(self, n: int) -> int:
        steps = [0 for _ in range(n + 2)]

        steps[n] = 1
        for i in range(n - 1, -1, -1):
            steps[i] = steps[i + 1] + steps[i + 2]

        return steps[0]
