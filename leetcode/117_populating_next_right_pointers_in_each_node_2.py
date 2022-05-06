"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        suspended = [root]
        while len(suspended) != 0:
            for i in range(len(suspended) - 1):
                suspended[i].next = suspended[i + 1]
            next_suspended = []
            for node in suspended:
                if node.left is not None:
                    next_suspended.append(node.left)
                if node.right is not None:
                    next_suspended.append(node.right)
            suspended = next_suspended
        return root


# 空間計算量をもうちょっとよさげにする解法：
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        dummy = Node()
        ptr = dummy
        parent = root
        while parent is not None:
            ptr.next = parent.left
            if parent.left is not None:
                ptr = ptr.next
            ptr.next = parent.right
            if parent.right is not None:
                ptr = ptr.next
            parent = parent.next
            if parent is None:
                ptr = dummy # reset ptr
                parent = dummy.next
        return root