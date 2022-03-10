# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ret = []
        queue = [root]
        while len(queue) != 0:
            ave = 0.0
            l = len(queue)
            next_level = []
            for _ in range(l):
                node = queue.pop()
                ave += node.val
                if node.left is not None:
                    next_level.append(node.left)
                if node.right is not None:
                    next_level.append(node.right)
            ret.append(ave / l)
            queue = next_level
        return ret
