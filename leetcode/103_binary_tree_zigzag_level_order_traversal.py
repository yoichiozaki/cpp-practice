# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        suspended = [root]
        level = 0
        ans = []
        while len(suspended) != 0:
            if level % 2 == 0:
                ans.append([n.val for n in suspended])
            else:
                ans.append([n.val for n in suspended][::-1])
            next_suspended = []
            for n in suspended:
                if n.left is not None:
                    next_suspended.append(n.left)
                if n.right is not None:
                    next_suspended.append(n.right)
            suspended = next_suspended
            level += 1
        return ans