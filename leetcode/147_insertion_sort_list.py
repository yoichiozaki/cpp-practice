# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        dummy = ListNode(val=-1, next=None)
        current = head
        prev = dummy
        nxt = None
        while current is not None:
            nxt = current.next
            while prev.next is not None and prev.next.val < current.val:
                prev = prev.next
            current.next = prev.next
            prev.next = current
            prev = dummy
            current = nxt
        return dummy.next
