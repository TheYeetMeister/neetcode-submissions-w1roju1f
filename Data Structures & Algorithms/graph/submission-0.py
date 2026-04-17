class Graph:
    
    def __init__(self):
        self.nodeDict = defaultdict(set)

    def addEdge(self, src: int, dst: int) -> None:
        self.nodeDict[src].add(dst)

    def removeEdge(self, src: int, dst: int) -> bool:
        if not dst in self.nodeDict[src]:
            return False
        
        self.nodeDict[src].remove(dst)
        return True

    def hasPath(self, src: int, dst: int) -> bool:
        visited = set()
        def dfs(node):
            if node in visited:
                return False
            elif node == dst:
                return True

            visited.add(node)

            for nei in self.nodeDict[node]:
                if dfs(nei):
                    return True
            
            return False
        
        return dfs(src)



