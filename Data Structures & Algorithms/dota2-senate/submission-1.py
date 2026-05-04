class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        queR = deque()
        queD = deque()
        n = len(senate)

        for i in range(n):
            if senate[i] == 'R':
                queR.append(i)
            else:
                queD.append(i)
        
        while queR and queD:
            if queR[0] < queD[0]:
                queD.popleft()
                queR.append(queR.popleft() + n)
            else:
                queR.popleft()
                queD.append(queD.popleft() + n)

        return "Radiant" if queR else "Dire"

        
