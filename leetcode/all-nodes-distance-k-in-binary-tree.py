# parentを追加で追いながらBFS
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        # mark parent
        node_to_parent = dict()

        def dfs(node, parent):
            if node is not None:
                node_to_parent[node] = parent
                dfs(node.left, node)
                dfs(node.right, node)
        dfs(root, None)

        # BFS
        has_visited = set()
        has_visited.add(target)
        suspended = [target]
        distance = 0
        while len(suspended) != 0:
            if distance == K:
                return [node.val for node in suspended]
            next_suspended = []
            for node in suspended:
                neighbors = [node.left, node.right, node_to_parent[node]]
                for neighbor in neighbors:
                    if neighbor is not None and neighbor not in has_visited:
                        next_suspended += [neighbor]
                        has_visited.add(neighbor)
            suspended = next_suspended
            distance += 1

        return []


# 工夫してDFS
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        ret = []

        def dfs(node, target):
            nonlocal ret
            if node is None:
                return -1
            if node is target:
                traverse_subtree(node, 0)
                return 1
            left = dfs(node.left, target)
            right = dfs(node.right, target)
            if left != -1:
                if left == K:
                    ret += [node.val]
                traverse_subtree(node.right, left + 1)
                return left + 1
            if right != -1:
                if right == K:
                    ret += [node.val]
                traverse_subtree(node.left, right + 1)
                return right + 1
            return -1

        def traverse_subtree(node, dist):
            nonlocal ret
            if node is None:
                return
            if dist == K:
                ret += [node.val]
            else:
                traverse_subtree(node.left, dist + 1)
                traverse_subtree(node.right, dist + 1)
        dfs(root, target)
        return ret
