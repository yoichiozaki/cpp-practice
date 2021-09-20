# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        preordered = []

        def rec(root):
            if root is None:
                return
            preordered.append(root)
            rec(root.left)
            rec(root.right)

        rec(root)
        for i in range(len(preordered)):
            preordered[i].left = None
            if i < len(preordered) - 1:
                preordered[i].right = preordered[i+1]
            else:
                preordered[i].right = None


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        prev = None

        # root以下をflattenしてprevに記録する
        def rec(root):
            nonlocal prev
            if root is None:
                return
            rec(root.right)
            rec(root.left)
            root.right = prev
            root.left = None
            prev = root

        rec(root)
