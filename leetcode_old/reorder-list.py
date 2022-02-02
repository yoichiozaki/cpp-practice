# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None:
            return head

        # get middle
        p1 = head
        p2 = head
        while p2.next is not None and p2.next.next is not None:
            p1 = p1.next
            p2 = p2.next.next

        # reverse the half after middle
        pre_middle = p1
        pre_current = p1.next
        while pre_current.next is not None:
            current = pre_current.next
            pre_current.next = current.next
            current.next = pre_middle.next
            pre_middle.next = current

        # interleave left hand side and right hand side
        p1 = head
        p2 = pre_middle.next
        while p1 is not pre_middle:
            pre_middle.next = p2.next
            p2.next = p1.next
            p1.next = p2
            p1 = p2.next
            p2 = pre_middle.next
