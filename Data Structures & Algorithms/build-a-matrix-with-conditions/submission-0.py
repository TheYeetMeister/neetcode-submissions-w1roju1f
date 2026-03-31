class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        nextRows = [[] for _ in range(k)]
        indegreesRow = [0 for _ in range(k)]

        nextCols = [[] for _ in range(k)]
        indegreesCol = [0 for _ in range(k)]

        for i, j in rowConditions:
            nextRows[i - 1].append(j - 1)
            indegreesRow[j - 1] += 1
        
        for i, j in colConditions:
            nextCols[i - 1].append(j - 1)
            indegreesCol[j - 1] += 1

        def topoSort(adjList: list[list], indegreeList: list[int]):
            def dfs(i, res: list):
                if indegreeList[i] != 0:
                    return

                res.append(i)
                indegreeList[i] -= 1

                for j in adjList[i]:
                    indegreeList[j] -= 1
                    dfs(j, res)
                
            res = []
            for i in range(len(indegreeList)):
                dfs(i, res)

            return res

        numIndex = [[0, 0] for _ in range(k)]
        rowOrdering = topoSort(nextRows, indegreesRow)
        colOrdering = topoSort(nextCols, indegreesCol)

        if len(rowOrdering) < k or len(colOrdering) < k:
            return []

        for i in range(k):
            numIndex[rowOrdering[i]][0] = i
            numIndex[colOrdering[i]][1] = i

        grid = [[0 for _ in range(k)] for _ in range(k)]

        for i in range(k):
            row = numIndex[i][0]
            col = numIndex[i][1]
            grid[row][col] = i + 1

        return grid
