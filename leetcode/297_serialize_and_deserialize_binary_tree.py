# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        values = []
        def helper(root):
            if root is not None:
                values.append(str(root.val))
                helper(root.left)
                helper(root.right)
            else:
                values.append("#")
        helper(root)
        return " ".join(values)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        values = iter(data.split())
        def helper():
            current = next(values)
            if current == "#":
                return None
            else:
                node = TreeNode(int(current))
                node.left = helper()
                node.right = helper()
                return node
        return helper()

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))