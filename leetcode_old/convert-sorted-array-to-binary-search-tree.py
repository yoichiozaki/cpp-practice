# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def _recurse(nums, low, high):
            if high < low:
                return None
            middle = (low + high) // 2
            root = TreeNode(val=nums[middle])
            root.left = _recurse(nums, low, middle-1)
            root.right = _recurse(nums, middle+1, high)
            return root
        return _recurse(nums, 0, len(nums)-1)
