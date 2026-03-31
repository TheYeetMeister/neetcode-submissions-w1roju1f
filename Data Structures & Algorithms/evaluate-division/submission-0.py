Index = namedtuple("Index", ["varNode", "currFactor"])

class VarNode:
    def __init__(self, var: str):
        self._var = var
        self._nei = []
        self._factor = []

    def addNei(self, varNode: VarNode, factor: int):
        self._nei.append(varNode)
        self._factor.append(factor)

    def getNeis(self) -> generator:
        for i in range(len(self._nei)):
            yield [self._nei[i], self._factor[i]]

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        nodes = {}

        for i in range(len(equations)):
            varA = equations[i][0]
            varB = equations[i][1]
            
            if not varA in nodes:
                nodes[varA] = VarNode(varA)

            if not varB in nodes:
                nodes[varB] = VarNode(varB)

            nodes[varA].addNei(nodes[varB], values[i])
            nodes[varB].addNei(nodes[varA], 1 / values[i])

        def bfs(varNodeA, varNodeB):
            if varNodeA == varNodeB:
                return 1
            
            visited = set([varNodeA])
            que = deque([Index(varNodeA, 1)])

            while que:
                top = que.popleft()

                if top.varNode == varNodeB:
                    return top.currFactor

                for neiNode, newFactor in top.varNode.getNeis():
                    if neiNode in visited:
                        continue

                    visited.add(neiNode)
                    newNode = Index(neiNode, newFactor * top.currFactor)
                    que.append(newNode)
        
            return -1

        res = []

        for i, j in queries:
            if not i in nodes or not j in nodes:
                res.append(-1)
                continue 

            res.append(bfs(nodes[i], nodes[j]))

        return res
                    
                    
