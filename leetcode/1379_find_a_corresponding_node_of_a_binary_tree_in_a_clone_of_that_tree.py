# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = None
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        def dfs(root):
            if root is None:
                return
            if root.val == target.val:
                self.ans = root
                return
            if root.left is not None:
                dfs(root.left)
            if root.right is not None:
                dfs(root.right)
        dfs(cloned)
        return self.ans