# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def helper(root):
            if root is None:
                return 0, None
            left_height, left_lca = helper(root.left)
            right_height, right_lca = helper(root.right)
            if left_height < right_height:
                return right_height + 1, right_lca
            if right_height < left_height:
                return left_height + 1, left_lca
            return right_height + 1, root
        return helper(root)[1]