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
            return root

        suspended = [root]
        while len(suspended) != 0:
            next_suspended = []
            for i in range(len(suspended)):
                if suspended[i].left is not None:
                    next_suspended.append(suspended[i].left)
                if suspended[i].right is not None:
                    next_suspended.append(suspended[i].right)
                if i < len(suspended) - 1:
                    suspended[i].next = suspended[i + 1]
            suspended = next_suspended

        return root


# Definition for a Node.
# class Node:
#     def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.next = next
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        dummy = Node()
        tail = dummy  # pointer to tail node at child level
        parent = root

        # 上からnextを設置していく
        while parent is not None:
            # tailを右に動かせるところまで動かす
            tail.next = parent.left
            if tail.next is not None:
                tail = tail.next
            tail.next = parent.right
            if tail.next is not None:
                tail = tail.next

            parent = parent.next
            if parent is None:
                tail = dummy
                parent = dummy.next

        return root
