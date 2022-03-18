# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        from hashlib import sha256

        def _hash(x):
            S = sha256()
            S.update(str.encode(x))
            return S.hexdigest()

        def merkle(node):
            if node is None:
                return ""
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


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def encode(root):
            suspended = [root]
            traversal = []
            while len(suspended) != 0:
                node = suspended.pop()
                if node is None:
                    traversal.append("#")
                    continue
                else:
                    traversal.append(str(node.val))
                    suspended.append(node.left)
                    suspended.append(node.right)
            return "-" + "-".join(traversal) + "-"
        return encode(subRoot) in encode(root)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def encode(root):
            if root is None:
                return "#"
            return "-" + str(root.val) + "-" + encode(root.left) + "-" + encode(root.right) + "-"
        return encode(subRoot) in encode(root)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def is_same(root1, root2):
            if root1 is None and root2 is None:
                return True
            if root1 is not None and root2 is None:
                return False
            if root1 is None and root2 is not None:
                return False
            return root1.val == root2.val and is_same(root1.left, root2.left) and is_same(root1.right, root2.right)
        result = False

        def dfs(root):
            nonlocal result
            if result:
                return
            if root is None:
                return
            if root.val == subRoot.val:
                result = is_same(root, subRoot)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        return result


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def is_same(root1, root2):
            if root1 is None and root2 is None:
                return True
            if root1 is not None and root2 is None:
                return False
            if root1 is None and root2 is not None:
                return False
            return root1.val == root2.val and is_same(root1.left, root2.left) and is_same(root1.right, root2.right)

        if root is None and subRoot is None:
            return True
        if root is not None and subRoot is None:
            return False
        if root is None and subRoot is not None:
            return False
        return is_same(root, subRoot) or self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
