# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if root is None:
            return False
        suspended = list()
        suspended.append((root, root.val))

        while len(suspended) != 0:
            u, sofar = suspended.pop()
            if u.left is None and u.right is None and sofar == targetSum:
                return True
            if u.left is not None:
                suspended.append((u.left, sofar + u.left.val))
            if u.right is not None:
                suspended.append((u.right, sofar + u.right.val))
        return False
