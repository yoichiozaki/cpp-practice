# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        # 初めてtargetより大きくなる位置を返す
        def binary_search(nums, target):
            ng = -1
            ok = len(nums)
            def is_ok(mid):
                return target < nums[mid]
            while 1 < abs(ok - ng):
                mid = (ok + ng) // 2
                if is_ok(mid):
                    ok = mid
                else:
                    ng = mid
            return ok
        
        def rec(nodes):
            if len(nodes) == 0:
                return None
            val = nodes.pop(0)
            pos = binary_search(nodes, val)
            root = TreeNode(val=val)
            root.left = rec(nodes[:pos])
            root.right = rec(nodes[pos:])
            return root
        
        return rec(preorder)