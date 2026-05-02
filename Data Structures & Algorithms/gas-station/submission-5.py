class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        res = []
        n = len(gas)
        m = 0
        currWindow = 0
        startingWindow = 0

        for i in range(n):
            res.append(gas[i] - cost[i])
            m += res[i]

            if currWindow == 0:
                startingWindow = i

            currWindow += res[i]

            if currWindow < 0:
                currWindow = 0

        if m < 0:
            return -1


        return startingWindow