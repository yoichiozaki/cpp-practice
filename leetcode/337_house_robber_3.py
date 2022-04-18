# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        memo = {} # {root: maximum amount of money the thief can rob from the tree}
        def _rob(root):
            if root in memo:
                return memo[root]
            if root is None:
                return 0
            val = 0
            if root.left is not None:
                val += _rob(root.left.left) + _rob(root.left.right)
            if root.right is not None:
                val += _rob(root.right.left) + _rob(root.right.right)
            money = max(root.val + val, _rob(root.left) + _rob(root.right))
            memo[root] = money
            return money
        return _rob(root)