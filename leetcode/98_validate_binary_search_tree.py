# どっちも全頂点を訪問するのでO(n)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def check(root, larger, smaller):
            if root is None:
                return True
            if not (larger < root.val < smaller):
                return False
            return check(root.left, larger, root.val) and check(root.right, root.val, smaller)
        return check(root, float("-inf"), float("inf"))


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        nodes = []
        def inorder(root):
            if root is None:
                return
            inorder(root.left)
            nodes.append(root.val)
            inorder(root.right)
        inorder(root)
        for i in range(1, len(nodes)):
            if not (nodes[i-1] < nodes[i]):
                return False
        return True