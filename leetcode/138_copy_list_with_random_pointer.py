"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        clone = Node(x=head.val)
        original_to_clone = {head: clone, None: None}
        ptr = head
        while ptr.next is not None:
            original_to_clone[ptr.next] = Node(x=ptr.next.val)
            original_to_clone[ptr].next = original_to_clone[ptr.next]
            ptr = ptr.next
        ptr = head
        while ptr is not None:
            original_to_clone[ptr].random = original_to_clone[ptr.random]
            ptr = ptr.next
        return original_to_clone[head]