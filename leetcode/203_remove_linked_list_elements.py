# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head is None:
            return None
        dummy_head = ListNode(val=-1, next=head)

        prev = dummy_head
        curr = head

        while curr is not None:
            if curr.val == val:
                prev.next = curr.next
                curr = curr.next
            else:
                curr = curr.next
                prev = prev.next

        return dummy_head.next
