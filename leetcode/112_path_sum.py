# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False

        suspended = [(root, root.val)]

        while len(suspended) != 0:
            node, sofar = suspended.pop()
            if node.left is None and node.right is None and sofar == targetSum:
                return True
            if node.left is not None:
                suspended.append((node.left, sofar + node.left.val))
            if node.right is not None:
                suspended.append((node.right, sofar + node.right.val))
        return False


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False

        suspended = [(root, root.val)]

        while len(suspended) != 0:
            node, sofar = suspended.pop(0)
            if node.left is None and node.right is None and sofar == targetSum:
                return True
            if node.left is not None:
                suspended.append((node.left, sofar + node.left.val))
            if node.right is not None:
                suspended.append((node.right, sofar + node.right.val))
        return False


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        ans = []

        def dfs(root, targetSum, ans):
            if root is not None:
                if root.left is None and root.right is None and root.val == targetSum:
                    ans.append(True)
                if root.left is not None:
                    dfs(root.left, targetSum - root.val, ans)
                if root.right is not None:
                    dfs(root.right, targetSum - root.val, ans)
        dfs(root, targetSum, ans)
        return len(ans) != 0
