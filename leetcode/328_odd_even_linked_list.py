# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        if head.next is None:
            return head
        odd_head = head
        even_head = head.next
        connection = head.next
        while even_head is not None:
            if even_head.next is None:
                break
            odd_head_next = even_head.next
            even_head_next = even_head.next.next
            odd_head.next = odd_head_next
            even_head.next = even_head_next
            odd_head = odd_head.next
            even_head = even_head.next
        odd_head.next = connection
        return head