class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 1:
            return 1

        res = [1 for i in range(n)]
        for i in range(n - 1, 0, -1):
            if ratings[i - 1] > ratings[i]:
                res[i - 1] = res[i] + 1
        
        for i in range(n - 1):
            if ratings[i + 1] > ratings[i] and res[i + 1] < res[i] + 1:
                res[i + 1] = res[i] + 1

        return sum(res)