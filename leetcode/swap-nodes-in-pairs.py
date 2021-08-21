# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        p1 = head
        p2 = head.next
        p1.val, p2.val = p2.val, p1.val

        while p1 is not None and p1.next is not None and p1.next.next is not None and p2 is not None and p2.next is not None and p2.next.next is not None:
            p1 = p1.next.next
            p2 = p2.next.next
            p1.val, p2.val = p2.val, p1.val

        return head


# 再帰
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        n = head.next
        head.next = self.swapPairs(n.next)
        n.next = head
        return n


# 繰り返し
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        dummy = ListNode(val=-1, next=None)
        prev = dummy
        first = head

        while first is not None and first.next is not None:
            second = first.next
            tmp = second.next

            second.next = first
            first.next = tmp
            prev.next = second

            prev = first
            first = tmp

        return dummy.next
