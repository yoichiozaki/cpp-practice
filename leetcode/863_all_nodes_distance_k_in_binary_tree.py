# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parents = dict()
        def dfs(node, parent):
            if node is not None:
                parents[node] = parent
                dfs(node.left, node)
                dfs(node.right, node)
        dfs(root, None)
        
        has_visited = set()
        has_visited.add(target)
        suspended = [target]
        distance = 0
        while len(suspended) != 0:
            if distance == k:
                return [node.val for node in suspended]
            next_suspended = []
            for node in suspended:
                neighbors = [node.left, node.right, parents[node]]
                for neighbor in neighbors:
                    if neighbor is not None and neighbor not in has_visited:
                        next_suspended.append(neighbor)
                        has_visited.add(neighbor)
            suspended = next_suspended
            distance += 1
        return []