# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def rec(l1, l2, carry):
            if l1 is None and l2 is None and carry == 0:
                return None
            val = carry
            val += l1.val if l1 is not None else 0
            val += l2.val if l2 is not None else 0
            head = ListNode(val=val % 10, next=None)
            l1_next = l1.next if l1 is not None else None
            l2_next = l2.next if l2 is not None else None
            head.next = rec(l1_next, l2_next, val // 10)
            return head
        return rec(l1, l2, 0)
