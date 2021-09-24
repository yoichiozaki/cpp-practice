# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        ret = []

        def rec(root, remain, sofar):
            if root is None:
                return
            if root.left is None and root.right is None and remain == root.val:
                ret.append(sofar + [root.val])
                return
            remain -= root.val
            rec(root.left, remain, sofar + [root.val])
            rec(root.right, remain, sofar + [root.val])
        rec(root, targetSum, [])
        return ret
