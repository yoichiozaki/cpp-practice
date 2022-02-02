# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ans = 0
        ptr = head
        while ptr is not None:
            ans = 2 * ans + ptr.val
            ptr = ptr.next
        return ans
