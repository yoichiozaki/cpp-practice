# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return None
        ptr = head
        length = 1
        while ptr.next is not None:
            ptr = ptr.next
            length += 1
        ptr.next = head
        diff = length - (k % length)
        ptr = head
        while 0 < diff:
            ptr = ptr.next
            diff -= 1
        move = length
        tail = ptr
        while 1 < move:
            tail = tail.next
            move -= 1
        tail.next = None
        return ptr