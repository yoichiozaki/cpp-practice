# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def rec(root, sum):
            if root is None:
                return 0
            sum = (2 * sum) + root.val
            if root.left is None and root.right is None:
                return sum
            return rec(root.left, sum) + rec(root.right, sum)
        return rec(root, 0)