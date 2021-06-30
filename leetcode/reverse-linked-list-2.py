# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if head is None:
            return head

        prev = None
        curr = head
        while 1 < left:
            prev = curr
            curr = curr.next
            left -= 1
            right -= 1

        tail = curr
        conn = prev

        while 0 < right:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
            right -= 1

        if conn is not None:
            conn.next = prev
        else:
            head = prev

        tail.next = curr
        return head
