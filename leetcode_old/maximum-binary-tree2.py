# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        # valは元になっている配列の右端に存在する
        # valが最大の要素ならrootがvalのleftになるだけ
        # valが最大の要素でないときvalはrootの右の部分木にいるはず

        if root is not None and root.val > val:
            root.right = self.insertIntoMaxTree(root.right, val)
            return root
        new_root = TreeNode(val=val)
        new_root.left = root
        return new_root
