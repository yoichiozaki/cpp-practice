# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        ans = []
        suspended = [root]
        while len(suspended) != 0:
            ans.append([n.val for n in suspended])
            next_suspended = []
            for n in suspended:
                if n.left is not None:
                    next_suspended.append(n.left)
                if n.right is not None:
                    next_suspended.append(n.right)
            suspended = next_suspended
        return ans