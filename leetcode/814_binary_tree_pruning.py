# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        def has_one(root):
            if root is None:
                return False
            l = has_one(root.left)
            r = has_one(root.right)
            if not l:
                root.left = None
            if not r:
                root.right = None
            return root.val == 1 or l or r
        return root if has_one(root) else None