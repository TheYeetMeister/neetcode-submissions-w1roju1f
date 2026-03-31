"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        createdNodes = {}

        def dfs(node):
            if node in createdNodes:
                return createdNodes[node]

            createdNodes[node] = Node(node.val)

            for nei in node.neighbors:
                createdNodes[node].neighbors.append(dfs(nei))

            return createdNodes[node]

        return dfs(node) if node else None