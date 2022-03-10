# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        tilts = []

        def rec(root):
            if root is None:
                return 0
            left_sum = rec(root.left)
            right_sum = rec(root.right)
            tilts.append(abs(left_sum - right_sum))
            return left_sum + root.val + right_sum
        rec(root)
        return sum(tilts)
