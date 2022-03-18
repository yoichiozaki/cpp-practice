# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        ans = ""

        def rec(node):
            nonlocal ans
            if node is None:
                return
            ans += str(node.val)
            if node.left is None and node.right is None:
                return
            ans += "("
            rec(node.left)
            ans += ")"
            if node.right is not None:
                ans += "("
                rec(node.right)
                ans += ")"
        rec(root)
        return ans


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if root is None:
            return ""

        def rec(node, sofar):
            if node is None:
                return sofar
            sofar += str(node.val)
            if node.left is None and node.right is None:
                return sofar
            if node.right is None:  # 右が空なら省略可という例外
                sofar = rec(node.left, sofar + "(")
                sofar += ")"
                return sofar
            sofar = rec(node.left, sofar + "(")
            sofar += ")"
            sofar = rec(node.right, sofar + "(")
            sofar += ")"
            return sofar
        return rec(root, "")
