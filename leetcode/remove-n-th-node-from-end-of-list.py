# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy_head = ListNode(val=-1, next=head)
        p1 = dummy_head
        p2 = dummy_head

        # p1 <-> p2 に距離をつける
        for _ in range(1 + n):
            p2 = p2.next

        # 平行移動
        while p2 is not None:
            p1 = p1.next
            p2 = p2.next

        p1.next = p1.next.next

        return dummy_head.next
