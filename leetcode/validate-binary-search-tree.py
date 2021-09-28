# 全頂点について 左部分木の最大値 < 自分 < 右部分木の最小値 が成立することを確認する
# Time: O(N)
# Space: O(depth of bst)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def rec(root, larger_than, less_than):
            if root is None:
                return True
            if not (larger_than < root.val < less_than):
                return False
            return rec(root.left, larger_than, min(root.val, less_than)) and rec(root.right, max(larger_than, root.val), less_than)
        return rec(root, float("-inf"), float("inf"))


# 全頂点を間順走査で集めて昇順になっていることを確認する
# Time: O(N), 上の解法と比較して定数倍遅い
# Space: O(N)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        inordered = []

        def inorder_traversal(root):
            if root is None:
                return
            inorder_traversal(root.left)
            inordered.append(root.val)
            inorder_traversal(root.right)
        inorder_traversal(root)

        for i in range(len(inordered) - 1):
            if inordered[i] >= inordered[i+1]:
                return False
        return True
