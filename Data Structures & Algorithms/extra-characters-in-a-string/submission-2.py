class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.endOfWord = False

class Solution:
    def getCharIndex(self, char):
        return ord(char) - ord('a')

    def createOneBranch(self, word: str):
        curr = self.root

        for char in word:
            index = self.getCharIndex(char)

            if not curr.children[index]:
               curr.children[index] = TrieNode()

            curr = curr.children[index]

        curr.endOfWord = True  

    def createDictTrie(self, dictionary: List[str]):
        self.root = TrieNode()

        for word in dictionary:
            self.createOneBranch(word)
        

    def oneWord(self, index: int):
        if self.dp[index] != -1:
            return self.dp[index]

        res = 1 + self.oneWord(index + 1)

        curr = self.root
        prevInd = index

        while index < len(self.s) and curr:
            if curr.endOfWord:
                res = min(res, self.oneWord(index))

            curr = curr.children[self.getCharIndex(self.s[index])]
            index += 1

        if curr and curr.endOfWord:
            res = min(res, self.oneWord(index))

        self.dp[prevInd] = res
        return self.dp[prevInd]


    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        self.dp = [-1 for _ in range(len(s) + 1)]
        self.dp[len(s)] = 0
        self.createDictTrie(dictionary)
        self.s = s

        return self.oneWord(0)
        