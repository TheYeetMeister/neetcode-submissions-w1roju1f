class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        nei = defaultdict(lambda: set())

        for i, j in trust:
            nei[i].add(j)

        def isAllValsTrust(person: int):
            for i in range(1, n + 1):
                if person == i:
                    continue

                if not person in nei[i]:
                    return False
            
            return True

        for i in range(1, n + 1):
            if len(nei[i]) == 0 and isAllValsTrust(i):
                return i

        return -1