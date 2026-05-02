class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        m = 0
        currWindow = 0
        startingWindow = 0

        for i in range(n):
            diff = gas[i] - cost[i]
            m += diff

            if currWindow == 0:
                startingWindow = i

            currWindow += diff

            if currWindow < 0:
                currWindow = 0

        if m < 0:
            return -1

        return startingWindow