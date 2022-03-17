# 「左右の部分木がbalanced」かつ「左右の部分木の高さの差が1以下」
# top-downなアプローチ
# Time: O(n^2)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True

        def height(root):
            if root is None:
                return 0
            left_height = height(root.left)
            right_height = height(root.right)
            return 1 + max(left_height, right_height)

        return abs(height(root.left) - height(root.right)) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)


# balancedでない木を部分木として持つ木はbalancedではないので，深さを計算している途中でその部分木がbalancedしているかを判定してしまえば良い
# bottom-upなアプローチ
# Time: O(n)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True

        def height(root):
            if root is None:
                return 0
            left_height = height(root.left)
            if left_height == -1:
                return -1
            right_height = height(root.right)
            if right_height == -1:
                return -1
            if abs(left_height - right_height) > 1:
                return -1
            return 1 + max(left_height, right_height)

        return height(root) != -1
