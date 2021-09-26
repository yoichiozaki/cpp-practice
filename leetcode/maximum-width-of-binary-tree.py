# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(root, level, order, start, end):
            if root is None:
                return 0
            if len(start) == level:
                start.append(order)
                end.append(order)
            else:
                end[level] = order

            current_width = end[level] - start[level] + 1
            left_subtree_width = dfs(root.left, level + 1, 2 * order, start, end)
            right_subtree_width = dfs(root.right, level + 1, 2 * order + 1, start, end)
            return max(current_width, max(left_subtree_width, right_subtree_width))
        return dfs(root, 0, 1, [], [])