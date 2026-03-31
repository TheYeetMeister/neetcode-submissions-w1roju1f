class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        def getDifferingChars(wordA: str, wordB: str):
            for i in range(min(len(wordA), len(wordB))):
                if wordA[i] != wordB[i]:
                    return (wordA[i], wordB[i])
            
            return None

        def getCharIndex(char: str):
            return ord(char) - ord('a')

        adj = [[] for _ in range(26)]
        indegrees = [-1 for _ in range(26)]
        nodes = 0

        def addNewChars(word):
            vertexes = 0
            for i in word:
                index = getCharIndex(i)
                if indegrees[index] == -1:
                    indegrees[index] = 0
                    vertexes += 1
            return vertexes
        
        nodes += addNewChars(words[0])
        for i in range(len(words) - 1):
            nodes += addNewChars(words[i + 1])
            
            edge = getDifferingChars(words[i], words[i + 1])
            if not edge:
                if len(words[i]) > len(words[i + 1]):
                    return ""
                continue

            indexOne = getCharIndex(edge[0])
            indexTwo = getCharIndex(edge[1])

            adj[indexOne].append(edge[1])
            indegrees[indexTwo] += 1

        def dfs(i):
            res = ""
            if indegrees[i] != 0:
                return res
            
            indegrees[i] -= 1

            res += chr(ord('a') + i)
            
            for char in adj[i]:
                index = getCharIndex(char)
                indegrees[index] -= 1
                res += dfs(index)

            return res

        res = ""
        for i in range(len(indegrees)):
            res += dfs(i)

        return res if len(res) == nodes else ""
