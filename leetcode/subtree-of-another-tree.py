# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
        def val_check(s, t):
            if s is not None and t is not None:
                return s.val == t.val and val_check(s.left, t.left) and val_check(s.right, t.right)
            if s is None and t is not None:
                return False
            if s is not None and t is None:
                return False
            if s is None and t is None:
                return True

        if val_check(root, subRoot):
            return True
        if root is None:
            return False
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
        from hashlib import sha256

        def _hash(x):
            S = sha256()
            S.update(str.encode(x))
            return S.hexdigest()

        def merkle(node):
            if node is None:
                return ''
            left_merkle = merkle(node.left)
            right_merkle = merkle(node.right)
            node.merkle = _hash(left_merkle + str(node.val) + right_merkle)
            return node.merkle

        merkle(root)
        merkle(subRoot)

        def dfs(node):
            if node is None:
                return False
            return node.merkle == subRoot.merkle or dfs(node.left) or dfs(node.right)

        return dfs(root)
