# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if root is None:
            return []
        
        ans = []
        def dfs(root, sofar, path):
            if root.left is None and root.right is None:
                if sofar + root.val == targetSum:
                    ans.append(path + [root.val])
                return
            if root.left is not None:
                dfs(root.left, sofar + root.val, path + [root.val])
            if root.right is not None:
                dfs(root.right, sofar + root.val, path + [root.val])
        dfs(root, 0, [])
        return ans