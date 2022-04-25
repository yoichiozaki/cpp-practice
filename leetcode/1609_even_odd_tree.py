# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        suspended = [root]
        level = 0
        while len(suspended) != 0:
            next_suspended = []
            for n in suspended:
                if n.left is not None:
                    next_suspended.append(n.left)
                if n.right is not None:
                    next_suspended.append(n.right)
            if level % 2 == 0:
                for i in range(len(suspended)):
                    if suspended[i].val % 2 == 0:
                        return False
                for i in range(1, len(suspended)):
                    if not (suspended[i-1].val < suspended[i].val):
                        return False
            else:
                for i in range(len(suspended)):
                    if suspended[i].val % 2 == 1:
                        return False
                for i in range(1, len(suspended)):
                    if not (suspended[i-1].val > suspended[i].val):
                        return False
            suspended = next_suspended
            level += 1
        return True