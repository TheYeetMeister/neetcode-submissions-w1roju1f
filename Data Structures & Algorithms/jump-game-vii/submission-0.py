class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        dp = [False for _ in range(n)]
        dp[0] = True

        for i in range(n):
            if not dp[i]:
                continue

            for j in range(i + minJump, min(i + maxJump + 1, n)):
                if s[j] == '0':
                    dp[j] = True

        return dp[-1]