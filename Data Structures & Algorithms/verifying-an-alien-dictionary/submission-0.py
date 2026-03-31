class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        wordValues = {}

        count = 0
        for char in order:
            count += 1
            wordValues[char] = count

        def cmpLessValues(a: str, b: str):
            i = 0

            endIndex = min(len(a), len(b))
            
            while i < endIndex:
                valueA = wordValues[a[i]]
                valueB = wordValues[b[i]]

                if valueA > valueB:
                    return False
                elif valueA < valueB:
                    return True
                i += 1

            return len(a) <= len(b)

        for i in range(len(words) - 1):
            if not cmpLessValues(words[i], words[i + 1]):
                return False
            
        return True
        