# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        left = self.invertTree(root.left)
        right = self.invertTree(root.right)
        root.left = right
        root.right = left
        return root


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        suspended = [root]
        while len(suspended) != 0:
            node = suspended.pop()
            node.left, node.right = node.right, node.left
            if node.left is not None:
                suspended.append(node.left)
            if node.right is not None:
                suspended.append(node.right)
        return root


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        suspended = [root]
        while len(suspended) != 0:
            node = suspended.pop(0)
            node.left, node.right = node.right, node.left
            if node.left is not None:
                suspended.append(node.left)
            if node.right is not None:
                suspended.append(node.right)
        return root
