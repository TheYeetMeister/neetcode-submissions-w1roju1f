import string

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordStep = set(wordList)

        if not endWord in wordStep:
            return 0

        queue = deque([beginWord])
        steps = 1

        while queue:
            n = len(queue)
            for i in range(n):
                frontWord = queue.popleft()

                if frontWord == endWord:
                    return steps

                for i in range(len(frontWord)):
                    for letter in string.ascii_lowercase:
                        if frontWord[i] == letter:
                            continue

                        newWord = frontWord[:i] + letter + frontWord[i + 1:]

                        if newWord in wordStep:
                            queue.append(newWord)
                            wordStep.remove(newWord)

            steps += 1


        return 0
        