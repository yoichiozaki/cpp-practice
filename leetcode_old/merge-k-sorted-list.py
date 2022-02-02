# Blute-force
# Time: O(n log n)
# Space: O(n)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        vals = []
        for node in lists:
            while node is not None:
                vals.append(node.val)
                node = node.next
        vals.sort()
        head = ListNode()
        ptr = head
        for val in vals:
            ptr.next = ListNode(val=val)
            ptr = ptr.next
        return head.next


# 一つずつ比較していく
# Time: O(kn), k := リスト数, 最小のノードを見つけるループでO(k)
# Space: O(n)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        ret = ListNode()
        ptr = ret
        current = []
        for node in lists:
            if node is None:
                continue
            current.append(node)

        while len(current) != 0:
            min_node = ListNode(val=float("inf"))
            min_idx = -1
            for idx, node in enumerate(current):
                if node.val < min_node.val:
                    min_node = node
                    min_idx = idx
            ptr.next = min_node
            ptr = ptr.next
            current = current[:min_idx] + current[min_idx + 1:]
            if min_node.next is not None:
                current.append(min_node.next)
        return ret.next


# PriorityQueueを使って最小値のListNodeを効率的に見つけるやり方
# Wrapperクラスで包むことで比較演算子を使えるようにする
# Time: O(n log k)
# Space: O(k)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        class Wrapper:
            def __init__(self, node):
                self.node = node

            def __lt__(self, other):
                return self.node.val < other.node.val

        ret = ListNode()
        ptr = ret

        from queue import PriorityQueue
        pq = PriorityQueue()

        for node in lists:
            if node is None:
                continue
            pq.put(Wrapper(node))

        while not pq.empty():
            min_node = pq.get().node
            ptr.next = min_node
            ptr = ptr.next
            if min_node.next is not None:
                pq.put(Wrapper(min_node.next))
        return ret.next


# queue.PriorityQueueではなくてheapqを使ったやり方
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        ret = ListNode()
        ptr = ret
        current = []
        for idx, node in enumerate(lists):
            if node is None:
                continue
            current.append((node.val, idx))
        heapq.heapify(current)

        while len(current) != 0:
            min_val, min_idx = heapq.heappop(current)
            ptr.next = ListNode(val=min_val)
            ptr = ptr.next
            if lists[min_idx].next is not None:
                heapq.heappush(current, (lists[min_idx].next.val, min_idx))
                lists[min_idx] = lists[min_idx].next
        return ret.next


# 「2つのリストをマージする」を順番に適用する
# Time: O(nk^2)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def merge_two_lists(list1, list2):
            dummy = ListNode(val=-1, next=None)
            current = dummy
            while list1 is not None and list2 is not None:
                if list1.val < list2.val:
                    current.next = list1
                    list1 = list1.next
                else:
                    current.next = list2
                    list2 = list2.next
                current = current.next
            if list1 is not None:
                current.next = list1
            else:
                current.next = list2
            return dummy.next
        head = ListNode(val=-1)
        for i in range(len(lists)):
            head.next = merge_two_lists(head.next, lists[i])
        return head.next


# 「2つのリストをマージする」を分割統治法で効率的に実施
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def merge_two_lists(list1, list2):
            dummy = ListNode(val=-1, next=None)
            current = dummy
            while list1 is not None and list2 is not None:
                if list1.val < list2.val:
                    current.next = list1
                    list1 = list1.next
                else:
                    current.next = list2
                    list2 = list2.next
                current = current.next
            if list1 is not None:
                current.next = list1
            else:
                current.next = list2
            return dummy.next

        N = len(lists)
        interval = 1

        if N == 0:
            return None

        while interval < N:
            for i in range(0, N - interval, interval * 2):
                lists[i] = merge_two_lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0]
