# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        right_side_view = []
        suspended = [root]
        while len(suspended) != 0:
            right_most_node = suspended[-1]
            right_side_view.append(right_most_node.val)
            next_suspended = []
            for node in suspended:
                if node.left is not None:
                    next_suspended.append(node.left)
                if node.right is not None:
                    next_suspended.append(node.right)
            suspended = next_suspended
        return right_side_view
