# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        values = []
        def helper(root):
            if root is None:
                return
            else:
                values.append(str(root.val))
                helper(root.left)
                helper(root.right)
        helper(root)
        return " ".join(values)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        values = data.split()
        def helper(larger, smaller):
            if len(values) <= self.idx:
                return None
            val = int(values[self.idx])
            if not (larger <= val <= smaller):
                return None
            root = TreeNode(val)
            self.idx += 1
            root.left = helper(larger, root.val)
            root.right = helper(root.val, smaller)
            return root
        self.idx = 0
        return helper(float("-inf"), float("inf"))
        
# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans