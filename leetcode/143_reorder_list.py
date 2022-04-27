# recursive: TLE
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
        if head is None:
            return None
        if head.next is None:
            return head
        next_head = head.next
        ptr = head
        prev = None
        while ptr.next is not None:
            prev = ptr
            ptr = ptr.next
        prev.next = None
        head.next = ptr
        if ptr is not next_head:
            ptr.next = self.reorderList(next_head)
        return head


# 真ん中計算して右側半分を反転させて交錯させる
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head is None:
            return head
        if head.next is None:
            return head
        
        # separete list at middle
        slower = head
        faster = head
        while faster.next is not None and faster.next.next is not None:
            slower = slower.next
            faster = faster.next.next
        rhs = slower.next
        slower.next = None
        
        # reverse right half side
        prev = None
        while rhs is not None:
            next_rhs = rhs.next
            rhs.next = prev
            prev = rhs
            rhs = next_rhs
        
        # interleave two lists
        rhs = prev
        lhs = head
        while rhs is not None:
            next_lhs, next_rhs = lhs.next, rhs.next
            lhs.next = rhs
            rhs.next = next_lhs
            lhs = next_lhs
            rhs = next_rhs
        return head
