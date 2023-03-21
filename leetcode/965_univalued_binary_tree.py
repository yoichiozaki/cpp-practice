# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        s = set()
        def rec(root):
            if root is None:
                return
            s.add(root.val)
            rec(root.left)
            rec(root.right)
        rec(root)
        return len(s) == 1