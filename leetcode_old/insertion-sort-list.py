# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        dummy_head = ListNode(val=-1, next=None)

        cur = head
        ptr = dummy_head  # `cur` will be placed as ptr.next
        nxt = None

        while cur is not None:
            nxt = cur.next  # 次の `cur` を先に保存

            # `ptr` の位置を探す
            while ptr.next is not None and ptr.next.val < cur.val:
                ptr = ptr.next

            # `cur` を適切な位置に挿入
            cur.next = ptr.next
            ptr.next = cur

            # 次のイテレーションのためのリセット
            ptr = dummy_head
            cur = nxt

        return dummy_head.next
