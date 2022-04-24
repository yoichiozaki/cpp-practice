# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        depths = dict()
        parents = dict()
        def dfs(root, parent, depth):
            if root is None:
                return
            depths[root] = depth
            parents[root] = parent
            dfs(root.left, root, depth + 1)
            dfs(root.right, root, depth + 1)
        dfs(root, None, 0)
        max_depth = max(depths.values())
        def ans(root):
            if root is None:
                return None
            if root.left is None and root.right is None:
                if depths[root] == max_depth:
                    return root
            l = ans(root.left)
            r = ans(root.right)
            if l is not None and r is not None:
                return root
            if l is None and r is not None:
                return r
            if l is not None and r is None:
                return l
            if l is None and r is None:
                return None
        return ans(root)
            