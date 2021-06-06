# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def _isValidBST(root, larger_than, less_than):
            if root is None:
                return True
            if root.val <= larger_than or less_than <= root.val:
                return False
            return _isValidBST(root.left, larger_than, min(less_than, root.val)) and _isValidBST(root.right, max(larger_than, root.val), less_than)
        return _isValidBST(root, float('-inf'), float('inf'))
