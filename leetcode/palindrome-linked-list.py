# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return head

        slower = head
        faster = head
        while faster is not None and faster.next is not None:
            faster = faster.next.next
            slower = slower.next

        stack = [slower.val]
        while slower.next is not None:
            slower = slower.next
            stack.append(slower.val)

        current = head

        while len(stack) != 0:
            if stack.pop() != current.val:
                return False
            current = current.next

        return True
