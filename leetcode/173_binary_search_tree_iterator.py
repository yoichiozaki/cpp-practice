# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.stack = []
        self._push(root)

    def next(self) -> int:
        ptr = self.stack.pop()
        self._push(ptr.right)
        return ptr.val

    def hasNext(self) -> bool:
        return len(self.stack) != 0

    def _push(self, node) -> None:
        while node is not None:
            self.stack.append(node)
            node = node.left

# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()

# 左方向まで見つつスタックに積んで逆順に拾う。その途中で右にもあるなら、その右部分木の最左端までスタックに積みなおして逆順に拾う。