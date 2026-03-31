class Solution:
    lambdaPos = [(1, 0),
                (-1, 0),
                (0, 1),
                (0, -1)]

    def exist(self, board: List[List[str]], word: str) -> bool:
        ROW: int = len(board)
        COL: int = len(board[0])

        def dfs(chosenSet: set, i: int, j :int, wordPos: int) -> bool:
            if wordPos == len(word):
                return True
            elif (i < 0 or i == ROW or
                    j < 0 or j == COL or
                    i * COL + j in chosenSet or
                    word[wordPos] != board[i][j]):
                return False

            chosenSet.add(i * COL + j)

            for k, m in self.lambdaPos:
                if dfs(chosenSet, i + k, j + m, wordPos + 1):
                        return True

            chosenSet.remove(i * COL + j)
            
            return False

        for i in range(ROW):
            for j in range(COL):
                chosenSet: set = set()
                if dfs(chosenSet, i, j, 0):
                    return True

        return False


            