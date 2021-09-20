# recursion
# Definition for a Node.
# class Node:
#     def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.next = next
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is not None and root.left is not None and root.right is not None:
            root.left.next = root.right
            if root.next is not None:
                root.right.next = root.next.left
            self.connect(root.left)
            self.connect(root.right)
        return root


# DFS
# Definition for a Node.
# class Node:
#     def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.next = next
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return

        suspended = [root]

        while len(suspended) != 0:
            curr = suspended.pop()
            if curr.left is not None and curr.right is not None:
                curr.left.next = curr.right
                if curr.next is not None:
                    curr.right.next = curr.next.left
                suspended.append(curr.left)
                suspended.append(curr.right)

        return root


# BFS
# Definition for a Node.
# class Node:
#     def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.next = next
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return

        suspended = [root]

        while len(suspended) != 0:
            curr = suspended.pop(0)
            if curr.left is not None and curr.right is not None:
                curr.left.next = curr.right
                if curr.next is not None:
                    curr.right.next = curr.next.left
                suspended.append(curr.left)
                suspended.append(curr.right)

        return root
