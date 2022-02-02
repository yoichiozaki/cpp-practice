# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy_head = ListNode(val=-1, next=head)
        p1 = dummy_head
        p2 = dummy_head

        for _ in range(k):
            p2 = p2.next

        target1 = p2

        while p2 is not None:
            p1 = p1.next
            p2 = p2.next

        target2 = p1

        target1.val, target2.val = target2.val, target1.val

        return dummy_head.next
