# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy_head = ListNode(val=-101, next=head)
        prev = dummy_head
        current = head
        while current is not None and current.next is not None:
            while current.val != current.next.val:
                current = current.next
                prev = prev.next
                if current.next is None:
                    return dummy_head.next
            while current is not None and current.next is not None and current.val == current.next.val:
                current = current.next
            prev.next = current.next
            current = current.next
            if current is None:
                return dummy_head.next
        return dummy_head.next
