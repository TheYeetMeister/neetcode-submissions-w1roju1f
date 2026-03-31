class Solution:
        class TrieNode:
                def __init__(self):
                        self.next = [None] * 26
                        self.isEndOfWord = False

        def insertWord(self, word: str, root: TrieNode):
                curr = root
                for c in word:
                        index = ord(c) - ord('a')

                        if not curr.next[index]:
                                curr.next[index] = self.TrieNode()

                        curr = curr.next[index]

                curr.isEndOfWord = True

        def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
                root = self.TrieNode()
                res = []
                sentence = []

                for word in wordDict:
                        self.insertWord(word, root)


                def dfs(i: int):
                        if i == len(s):
                                res.append(" ".join(sentence))
                                return
                        curr = root
                        subword = ""

                        for j in range(i, len(s)):
                                if ord('z') < ord(s[j]) or ord(s[j]) < ord('a'):
                                        return
                                subword += s[j]

                                curr = curr.next[ord(s[j]) - ord('a')]

                                if not curr:
                                        break
                                
                                if curr.isEndOfWord:
                                        sentence.append(subword)
                                        dfs(j + 1)
                                        sentence.pop()

                dfs(0)

                return res
