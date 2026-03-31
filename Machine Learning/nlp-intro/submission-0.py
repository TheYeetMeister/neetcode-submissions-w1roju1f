import torch
import torch.nn as nn
from torchtyping import TensorType

# torch.tensor(python_list) returns a Python list as a tensor
class Solution:
    def addSentenceList(self, wordList: List[str], allWords: List[List[str]])-> int:
        longestSentence = 0

        for sent in wordList:
            allWords.append([])
            for word in sent.split():
                allWords[-1].append(word)
            
            longestSentence = max(len(allWords[-1]), longestSentence)

        return longestSentence

    def createSortedWordList(self, allWords: List[str]):
        visitedSet = set()
        sortedWordList = []

        for wordList in allWords:
            for word in wordList:
                if not word in visitedSet:
                    visitedSet.add(word)
                    sortedWordList.append(word)

        sortedWordList.sort()

        return sortedWordList

    def rankWord(self, word: str, sortedWordList: List[str]):
        rank = 1

        for i in sortedWordList:
            if i == word:
                return rank
            
            rank += 1
        
        return -1


    def get_dataset(self, positive: List[str], negative: List[str]) -> TensorType[float]:
        allWords = []
        longestSentence: int = 0

        longestSentence = max(self.addSentenceList(positive, allWords), longestSentence)
        longestSentence = max(self.addSentenceList(negative, allWords), longestSentence)

        sortedWordList = self.createSortedWordList(allWords)
        
        for i in range(len(allWords)):
            for j in range(len(allWords[i])):
                allWords[i][j] = self.rankWord(allWords[i][j], sortedWordList)

            for _ in range(len(allWords[i]), longestSentence):
                allWords[i].append(0)

        return torch.tensor(allWords)


        
        