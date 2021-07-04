# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parent_val = root.val
        p_val = p.val
        q_val = q.val

        if parent_val < p_val and parent_val < q_val:
            return self.lowestCommonAncestor(root.right, p, q)

        if p_val < parent_val and q_val < parent_val:
            return self.lowestCommonAncestor(root.left, p, q)

        return root

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        pointer = root
        p_val = p.val
        q_val = q.val

        while pointer is not None:
            parent_val = pointer.val
            if parent_val < p_val and parent_val < q_val:
                pointer = pointer.right
            elif p_val < parent_val and q_val < parent_val:
                pointer = pointer.left
            else:
                return pointer
