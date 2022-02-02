# Top Down Merge Sort
# Time: O(n log n)
# Space: O(log n) = 再帰の深さ分のcall stack
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:

        def merge_sort(head):
            if head is None or head.next is None:
                return head
            middle = get_middle(head)
            left_side = merge_sort(head)
            right_side = merge_sort(middle)
            return merge(left_side, right_side)

        def merge(list1, list2):
            dummy_head = ListNode(val=-1, next=None)
            tail = dummy_head
            while list1 is not None and list2 is not None:
                if list1.val < list2.val:
                    tail.next = list1
                    list1 = list1.next
                    tail = tail.next
                else:
                    tail.next = list2
                    list2 = list2.next
                    tail = tail.next

            tail.next = list1 if list1 is not None else list2
            return dummy_head.next

        def get_middle(head):
            prev_middle = None
            while head is not None and head.next is not None:
                prev_middle = head if prev_middle is None else prev_middle.next
                head = head.next.next
            middle = prev_middle.next
            prev_middle.next = None
            return middle

        return merge_sort(head)


# Bottom Up Merge Sort
# 1 -> 2 -> 4 -> でいきなりマージソート
# Time: O(n log n)
# Space: O(1)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        tail = ListNode(val=-1, next=None)
        next_start = ListNode(val=-1, next=None)

        def merge_sort(head):
            nonlocal tail
            nonlocal next_start
            if head is None or head.next is None:
                return head

            length = 0
            p = head
            while p is not None:
                p = p.next
                length += 1

            start = head
            dummy_head = ListNode(val=-1, next=None)

            window_size = 1
            while window_size < length:
                tail = dummy_head
                while start is not None:
                    if start.next is None:
                        tail.next = start
                        break
                    middle = get_middle(start, window_size)
                    merge(start, middle)
                    start = next_start
                window_size *= 2
                start = dummy_head.next
            return dummy_head.next

        def get_middle(start, window_size):
            nonlocal tail
            nonlocal next_start
            prev_middle = start
            end = start.next

            index = 1
            while index < window_size and (prev_middle.next is not None or end.next is not None):
                if end.next is not None:
                    end = end.next.next if end.next.next is not None else end.next
                if prev_middle.next is not None:
                    prev_middle = prev_middle.next
                index += 1
            middle = prev_middle.next
            prev_middle.next = None
            next_start = end.next
            end.next = None
            return middle

        def merge(list1, list2):
            nonlocal tail
            nonlocal next_start
            dummy_head = ListNode(val=-1, next=None)
            new_tail = dummy_head
            while list1 is not None and list2 is not None:
                if list1.val < list2.val:
                    new_tail.next = list1
                    list1 = list1.next
                    new_tail = new_tail.next
                else:
                    new_tail.next = list2
                    list2 = list2.next
                    new_tail = new_tail.next
            new_tail.next = list1 if list1 is not None else list2

            while new_tail.next is not None:
                new_tail = new_tail.next

            tail.next = dummy_head.next
            tail = new_tail

        return merge_sort(head)
