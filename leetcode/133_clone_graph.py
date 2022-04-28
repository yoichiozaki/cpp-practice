"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        clone = Node(val=node.val)
        original_to_clone = {node: clone}
        def dfs(node):
            for neighbor in node.neighbors:
                if neighbor not in original_to_clone:
                    original_to_clone[neighbor] = Node(val=neighbor.val)
                    dfs(neighbor)
                original_to_clone[node].neighbors.append(original_to_clone[neighbor])
        dfs(node)
        return original_to_clone[node]