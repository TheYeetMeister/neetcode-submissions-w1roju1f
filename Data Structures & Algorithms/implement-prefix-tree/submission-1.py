class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.endOfWord = False

class PrefixTree:
    def __init__(self):
        self.root = TrieNode()

    def _calCharIndex(self, char: str) -> int:
        return ord(char) - ord('a')

    def _getPhraseNode(self, phrase: str) -> TrieNode:
        curr = self.root

        for char in phrase:
            index = self._calCharIndex(char)

            curr = curr.children[index]

            if not curr:
                return None

        return curr

    def insert(self, word: str) -> None:
        curr = self.root

        for char in word:
            index = self._calCharIndex(char)

            if not curr.children[index]:
                curr.children[index] = TrieNode()

            curr = curr.children[index]
        
        curr.endOfWord = True

    def search(self, word: str) -> bool:
        node: TrieNode = self._getPhraseNode(word)

        return node.endOfWord if TrieNode else False
        

    def startsWith(self, prefix: str) -> bool:
        node: TrieNode = self._getPhraseNode(prefix)

        return node != None
        
        