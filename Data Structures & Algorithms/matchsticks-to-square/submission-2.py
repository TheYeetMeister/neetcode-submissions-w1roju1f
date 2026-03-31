class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        fullLength = sum(matchsticks)

        if fullLength % 4 > 0:
            return False

        matchsticks.sort(reverse = True)
        limit = fullLength / 4
        lengths = [0 for _ in range(4)]

        def dfs(i :int):
            if i == len(matchsticks):
                return True

            for k in range(4):
                lengths[k] += matchsticks[i]
                
                if lengths[k] <= limit and dfs(i + 1):
                    return True
                    
                lengths[k] -= matchsticks[i]

            return False

        return dfs(0)
