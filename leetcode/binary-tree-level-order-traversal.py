# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        suspended = []
        suspended.append(root)

        lsts = []
        level = 0

        while len(suspended) != 0:
            if len(lsts) == level:
                lsts.append([])
            next_suspended = []
            for u in suspended:
                lsts[level].append(u.val)
                if u.left is not None:
                    next_suspended.append(u.left)
                if u.right is not None:
                    next_suspended.append(u.right)
            suspended = next_suspended
            level += 1

        return lsts
