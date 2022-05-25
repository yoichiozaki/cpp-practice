# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        values = set()
        def dfs(root):
            if root is None:
                return
            values.add(root.val)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        values = sorted(list(values))
        if len(values) < 2:
            return -1
        return values[1]