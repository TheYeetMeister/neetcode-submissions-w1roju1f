class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root

        for char in word:
            index = ord(char) - ord('a')
            if not curr.children[index]:
                curr.children[index] = TrieNode()

            curr = curr.children[index]

        curr.endOfWord = True
        
    def partialSearch(self, curr: TrieNode, word: str, index: int) -> bool:
        while len(word) > index:
            if word[index] == ".":
                for child in curr.children:
                    if child and self.partialSearch(child, word, index + 1):
                        return True
                
                return False

            curr = curr.children[ord(word[index]) - ord('a')]
            index += 1

            if not curr:
                return False

        return curr.endOfWord


    def search(self, word: str) -> bool:
        return self.partialSearch(self.root, word, 0)
        
