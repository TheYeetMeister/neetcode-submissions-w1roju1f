class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def dfs(stringSet: String, openCnt: int, closeCnt: int):
            if openCnt == n and closeCnt == n:
                res.append(stringSet)
                return

            if closeCnt < openCnt:
                dfs(stringSet + ")", openCnt, closeCnt + 1)
            if openCnt < n:
                dfs(stringSet + "(", openCnt + 1, closeCnt)
        
        dfs("", 0, 0)

        return res
            
        