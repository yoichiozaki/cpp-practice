# ある頂点がその親から見て左右にどれぐらい位置がずれるのかは、2 ^ (木の深さ - その頂点の高さの差) / 2 で計算できる
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        def calc_height(root):
            if root is None:
                return 0
            return max(calc_height(root.left), calc_height(root.right)) + 1
        height = calc_height(root)
        width = 2 ** height - 1
        ans = [["" for _ in range(width)] for _ in range(height)]
        def dfs(root, h, w):
            if root is None:
                return
            ans[h][w] = str(root.val)
            dfs(root.left, h + 1, w - 2 ** (height - h - 1 - 1))
            dfs(root.right, h + 1, w + 2 ** (height - h - 1 - 1))
        dfs(root, 0, width // 2)
        return ans