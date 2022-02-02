# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return False
        slower = head
        faster = head
        while faster.next is not None and faster.next.next is not None:
            slower = slower.next
            faster = faster.next.next
            if slower is faster:
                return True
        return False
