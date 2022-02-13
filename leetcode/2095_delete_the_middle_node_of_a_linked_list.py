# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        if head.next is None:
            return None
        prev = head
        slower = head
        faster = head
        while faster is not None and faster.next is not None:
            faster = faster.next.next
            prev = slower
            slower = slower.next
        prev.next = slower.next
        return head


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        if head.next is None:
            return None
        # この時点で長さ2以上のリストになってる
        slower = head
        faster = head.next.next  # 初期値としてfasterを一回先に進めておくことでslowerがprev相当になる
        while faster is not None and faster.next is not None:  # ループの条件がfasterのみで決まるのでslowerをprev扱いしても問題ない
            faster = faster.next.next
            slower = slower.next
        slower.next = slower.next.next  # slowerがprev相当なのでここでslower.nextを飛ばす
        return head
