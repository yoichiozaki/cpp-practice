# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def rec(root):
            if root is None:
                return
            root.left, root.right = root.right, root.left
            rec(root.left)
            rec(root.right)

        rec(root)
        return root


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root

        stack = []
        stack.append(root)

        while len(stack) != 0:
            node = stack.pop()
            left = node.left
            right = node.right
            node.left, node.right = node.right, node.left
            if left is not None:
                stack.append(left)
            if right is not None:
                stack.append(right)

        return root


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root

        que = []
        que.append(root)

        while len(que) != 0:
            node = que.pop(0)
            left = node.left
            right = node.right
            node.left, node.right = node.right, node.left
            if left is not None:
                que.append(left)
            if right is not None:
                que.append(right)

        return root
