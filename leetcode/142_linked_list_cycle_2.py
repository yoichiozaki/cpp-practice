# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        if head.next is None:
            return None
        faster = head
        slower = head
        has_loop = False
        while faster.next is not None and faster.next.next is not None: # fasterが先に行くのでfasterが進めるまで進む
            slower = slower.next
            faster = faster.next.next
            if slower == faster:
                has_loop = True
                slower = head
                break
        if has_loop:
            while slower != faster:
                slower = slower.next
                faster = faster.next
            return faster
        return None
            