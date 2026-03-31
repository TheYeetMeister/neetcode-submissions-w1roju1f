class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        res = []

        ROW: int = len(heights)
        COL: int = len(heights[0])

        deltaDir = [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1]
        ]

        pacificReachable = [[False for _ in range(COL)] for _ in range(ROW)]

        def dfs(prev: int, i: int, j: int, performedFunction: Callable, visitedList: list[list[int]]):
            if (i < 0 or i == ROW or
                j < 0 or j == COL or
                prev > heights[i][j] or 
                visitedList[i][j]
            ):
                return
            
            performedFunction(i, j)

            for k, m in deltaDir:
                dfs(heights[i][j], i + k, j + m, performedFunction, visitedList)
        
        def flipPacific(i: int, j: int):
            pacificReachable[i][j] = True

        for i in range(ROW):
            dfs(0, i, 0, flipPacific, pacificReachable)
        
        for j in range(1, COL):
            dfs(0, 0, j, flipPacific, pacificReachable)

        

        atlanticReachable = [[False for _ in range(COL)] for _ in range(ROW)]

        def flipAtlantic(i: int, j: int):
            if pacificReachable[i][j]:
                res.append([i, j])
                
            atlanticReachable[i][j] = True
        
        for i in range(ROW):
            dfs(0, i, COL - 1, flipAtlantic, atlanticReachable)
        
        for j in range(COL):
            dfs(0, ROW - 1, j, flipAtlantic, atlanticReachable)

        return res

            
