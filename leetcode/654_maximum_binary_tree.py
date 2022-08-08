# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def build(root, nums):
            if len(nums) == 0:
                return None
            max_num = max(nums)
            max_idx = nums.index(max_num)
            if root is None:
                root = TreeNode(val=max_num)
            root.left = build(root.left, nums[:max_idx])
            root.right = build(root.right, nums[max_idx + 1:])
            return root
        return build(None, nums)


# build関数の役割がこっちのほうが明確に見える。
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
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