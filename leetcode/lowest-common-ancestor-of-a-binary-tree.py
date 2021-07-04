# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        lca = None

        def rec(current):
            nonlocal lca
            if current is None:
                return False

            left_flag = rec(current.left)
            right_flag = rec(current.right)

            middle_flag = current == p or current == q

            if 2 <= left_flag + right_flag + middle_flag:
                lca = current

            return left_flag or right_flag or middle_flag

        rec(root)
        return lca


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        stack = [root]
        memo = {root: None}

        while p not in memo or q not in memo:
            node = stack.pop()
            if node.left is not None:
                memo[node.left] = node
                stack.append(node.left)
            if node.right is not None:
                memo[node.right] = node
                stack.append(node.right)

        p_ancestors = set()
        while p is not None:
            p_ancestors.add(p)
            p = memo[p]

        while q not in p_ancestors:
            q = memo[q]

        return q
