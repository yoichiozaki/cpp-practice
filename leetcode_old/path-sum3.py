# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        num_path = 0
        cache = {0: 1}  # {path_sum: num_of_path}

        def dfs(root, target, sofar_sum):
            nonlocal num_path
            if root is None:
                return

            sofar_sum += root.val
            subpath_sum = sofar_sum - target

            if subpath_sum in cache:
                num_path += cache[subpath_sum]

            if sofar_sum in cache:
                cache[sofar_sum] += 1
            else:
                cache[sofar_sum] = 1

            dfs(root.left, target, sofar_sum)
            dfs(root.right, target, sofar_sum)
            cache[sofar_sum] -= 1

        dfs(root, targetSum, 0)
        return num_path


# Brute-Force: TLE
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        num_path = 0

        def dfs(root, remain):
            if root is None:
                return
            check(root, remain)
            dfs(root.left, remain)
            dfs(root.right, remain)

        def check(node, remain):
            nonlocal num_path
            if node is None:
                return
            if node.val == remain:
                num_path += 1
            check(node.left, remain - node.val)
            check(node.right, remain - node.val)

        dfs(root, sum)
        return num_path
