# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None
        faster = head
        slower = head
        while faster is not None and faster.next is not None:
            faster = faster.next.next
            slower = slower.next
        return slower
