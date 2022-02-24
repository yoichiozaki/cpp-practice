# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        prv = None
        cur = head
        while cur is not None:
            nxt = cur.next
            cur.next = prv
            prv = cur
            cur = nxt
        return prv
