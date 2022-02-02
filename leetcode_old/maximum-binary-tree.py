# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        def build(nums, left, right):
            if left == right:
                return None
            max_val = max(nums[left:right])
            max_idx = nums.index(max_val)
            root = TreeNode(val=max_val)
            root.left = build(nums, left, max_idx)
            root.right = build(nums, max_idx + 1, right)
            return root

        return build(nums, 0, len(nums))
