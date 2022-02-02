# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        ret = []
        que = [root]
        while len(que) != 0:
            ave = 0
            l = len(que)
            next_level = []
            for _ in range(l):
                node = que.pop()
                ave += node.val
                if node.left is not None:
                    next_level.append(node.left)
                if node.right is not None:
                    next_level.append(node.right)
            ret.append(ave / l)
            que = next_level
        return ret
