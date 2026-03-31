class TrieNode():
    def __init__(self):
        self.children = [None] * 26
        self.endOfWord = False
        self.word = ""
        self.wordCount = 0

class Solution:
    def calCharValue(self, char):
        return ord(char) - ord('a')

    def createTrie(self, words: List[str]):
        self.root = TrieNode()

        for word in words:
            curr = self.root

            for char in word:
                index = self.calCharValue(char)

                if not curr.children[index]:
                    curr.children[index] = TrieNode()

                curr = curr.children[index]
                curr.wordCount += 1
            curr.word = word
            curr.endOfWord = True
                
                

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.createTrie(words)

        ROW = len(board)
        COL = len(board[0])
        chosenVals = set()
        wordsFound = []
        deltaDir = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        def calIndex(i: int, j: int):
            return i * COL + j

        def dfs(i: int, j: int, curr: TrieNode):
            if (i < 0 or i == ROW or
                j < 0 or j == COL or
                calIndex(i, j) in chosenVals):
                return False

            index = self.calCharValue(board[i][j])
            curr = curr.children[index]

            if not curr or curr.wordCount == 0:
                return False

            curr.wordCount -= 1
            chosenVals.add(calIndex(i, j))
            if curr.endOfWord:
                curr.endOfWord = False
                wordsFound.append(curr.word)
            
            for k, m in deltaDir:
                if dfs(i + k, j + m, curr):
                    chosenVals.remove(calIndex(i, j))
                    return True

            curr.wordCount += 1
            chosenVals.remove(calIndex(i, j))
            return False

        for i in range(ROW):
            for j in range(COL):
                while dfs(i, j, self.root):
                    print(wordsFound)
                    print(self.root.wordCount)

        return wordsFound
            


