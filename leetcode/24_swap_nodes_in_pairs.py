# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        if head.next is None:
            return head
        dummy = ListNode(val=-1, next=None)
        prev = dummy
        first = head
        while first is not None and first.next is not None:
            second = first.next
            next_first = second.next
            second.next = first
            first.next = next_first
            prev.next = second
            prev = first
            first = next_first
        return dummy.next