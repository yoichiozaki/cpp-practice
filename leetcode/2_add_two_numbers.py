# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def helper(carry, l1, l2):
            if carry is None and l1 is None and l2 is None:
                return None
            val = 0
            if carry is not None:
                val += carry.val
            if l1 is not None:
                val += l1.val
            if l2 is not None:
                val += l2.val
            added = ListNode(val % 10)
            next_carry = None
            if val // 10 != 0:
                next_carry = ListNode(val // 10)
            next_l1 = None
            if l1 is not None:
                next_l1 = l1.next
            next_l2 = None
            if l2 is not None:
                next_l2 = l2.next
            added.next = helper(next_carry, next_l1, next_l2)
            return added
        return helper(ListNode(0), l1, l2)