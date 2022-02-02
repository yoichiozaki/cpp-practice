# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slower = head
        faster = head
        while faster is not None and faster.next is not None:
            faster = faster.next.next
            slower = slower.next
        return slower
