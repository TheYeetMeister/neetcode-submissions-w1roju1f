class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)
        
        row = [0] * (m + 1)

        for i in range(n - 1, -1, -1):
            newRow = [0] * (m + 1)

            for j in range(m - 1, -1, -1):
                newRow[j] = max(row[j], newRow[j + 1])

                if text1[i] == text2[j]:
                    newRow[j] = max(newRow[j], 1 + row[j + 1])
            
            row = newRow

        return row[0]