# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        if head is None:
            return [None for _ in range(k)]
        tail = head
        length = 1
        while tail.next is not None:
            tail = tail.next
            length += 1

        window, remainder = length // k, length % k

        ans = []
        curr = head
        for i in range(k):
            subhead = ListNode(val=-1, next=None)
            writing = ListNode(val=-1, next=None)
            for j in range(window + (i < remainder)):
                if j == 0:
                    subhead = writing
                writing.next = ListNode(val=curr.val, next=None)
                writing = writing.next
                if curr is not None:
                    curr = curr.next
            ans.append(subhead.next)
        return ans
