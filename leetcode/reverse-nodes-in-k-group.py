# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        ptr = head
        cnt = 0
        while cnt < k:
            if ptr == None:
                return head
            ptr = ptr.next
            cnt += 1

        nxt = self.reverseKGroup(ptr, k)
        while 0 < cnt:
            pre = head.next
            head.next = nxt
            nxt = head
            head = pre
            cnt -= 1
        return nxt
