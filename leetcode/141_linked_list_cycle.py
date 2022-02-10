# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return False
        faster = head
        slower = head
        while faster.next is not None and faster.next.next is not None:
            faster = faster.next.next
            slower = slower.next
            if faster is slower:
                return True
        return False
