# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        def rec(root):
            if root is None:
                return (0, 0, 0)
            left_sum, left_size, left_ans = rec(root.left)
            right_sum, right_size, right_ans = rec(root.right)
            subtree_sum = left_sum + root.val + right_sum
            subtree_size = left_size + 1 + right_size
            if subtree_sum // subtree_size == root.val:
                return (subtree_sum, subtree_size, left_ans + right_ans + 1)
            else:
                return (subtree_sum, subtree_size, left_ans + right_ans)

        return rec(root)[2]