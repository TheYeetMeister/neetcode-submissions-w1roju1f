class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wordSet = set()
        res = []
        sentence = []

        for word in wordDict:
            wordSet.add(word)
        
        def dfs(i: int):
            if i == len(s):
                res.append(" ".join(sentence))
                return

            subword = ""

            for j in range(i, len(s)):
                subword += s[j]

                if subword in wordSet:
                    sentence.append(subword)
                    dfs(j + 1)
                    sentence.pop()
        dfs(0)
        return res
