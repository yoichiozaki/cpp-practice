# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return None
        faster = head
        slower = head
        while faster is not None and faster.next is not None:
            faster = faster.next.next
            slower = slower.next
        stack = []
        while slower is not None:
            stack.append(slower.val)
            slower = slower.next
        current = head
        while len(stack) != 0:
            if stack.pop() != current.val:
                return False
            current = current.next
        return True
