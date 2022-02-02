# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return head

        tail = head
        length = 1
        while tail.next is not None:
            tail = tail.next
            length += 1

        k %= length

        tail.next = head

        ptr = head
        for _ in range(length - k - 1):
            ptr = ptr.next

        ans = ptr.next
        ptr.next = None
        return ans

# TLE
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return head
        dummy_head = ListNode(val=-1, next=head)
        prev = dummy_head
        curr = head
        while 0 < k:
            while curr.next is not None:
                curr = curr.next
                prev = prev.next
            prev.next = None
            curr.next = dummy_head.next
            dummy_head.next = curr
            prev = dummy_head
            curr = dummy_head.next
            k -= 1
        return dummy_head.next
