class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False for _ in range(len(s) + 1)]
        dp[-1] = True

        for i in range(len(s), -1, -1):
            for word in wordDict:
                j = len(word)
                if i + j <= len(s) and s[i: i + j] == word and dp[i + j]:
                    dp[i] = dp[i + j]
                    break

        return dp[0]
