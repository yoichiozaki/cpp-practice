# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head is None:
            return head

        prev = None
        curr = head

        while 1 < left:
            prev = curr
            curr = curr.next
            left -= 1
            right -= 1

        connection = prev
        reversed_tail = curr

        while 0 < right:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
            right -= 1

        if connection is not None:
            connection.next = prev
        else:
            head = prev
        reversed_tail.next = curr

        return head
