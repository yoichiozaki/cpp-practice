# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        values = []
        p = head
        while p is not None:
            values.append(p.val)
            p = p.next
        values.sort()
        p = head
        idx = 0
        while p is not None:
            p.val = values[idx]
            p = p.next
            idx += 1
        return head



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        if head.next is None:
            return head
        prev = None
        slower = head
        faster = head
        while faster is not None and faster.next is not None:
            prev = slower
            slower = slower.next
            faster = faster.next.next
        prev.next = None
        left = head
        right = slower
        def merge(left, right):
            dummy = ListNode(val=-1)
            ptr = dummy
            while left is not None and right is not None:
                if left.val < right.val:
                    ptr.next = left
                    left = left.next
                else:
                    ptr.next = right
                    right = right.next
                ptr = ptr.next
            if left is not None:
                ptr.next = left
            else: # right is not None:
                ptr.next = right
            return dummy.next
        left = self.sortList(left)
        right = self.sortList(right)
        return merge(left, right)


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def split(head):
            prev = None
            slower = head
            faster = head
            while faster is not None and faster.next is not None:
                prev = slower
                slower = slower.next
                faster = faster.next.next
            prev.next = None
            return head, slower
        
        def merge(left, right):
            dummy = ListNode(val=-1)
            ptr = dummy
            while left is not None and right is not None:
                if left.val < right.val:
                    ptr.next = left
                    left = left.next
                else:
                    ptr.next = right
                    right = right.next
                ptr = ptr.next
            if left is not None:
                ptr.next = left
            if right is not None:
                ptr.next = right
            return dummy.next
        
        def sort_list(head):
            # Basecase
            if head is None:
                return None
            if head.next is None:
                return head
            left, right = split(head)
            return merge(sort_list(left), sort_list(right))
        
        return sort_list(head)