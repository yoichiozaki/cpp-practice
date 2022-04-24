# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        cnt = dict()
        def traverse(root):
            if root is None:
                return
            if root.val not in cnt:
                cnt[root.val] = 1
            else:
                cnt[root.val] += 1
            traverse(root.left)
            traverse(root.right)
        traverse(root)
        max_cnt = max(cnt.values())
        return [n for n in cnt if cnt[n] == max_cnt]