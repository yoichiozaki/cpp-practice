class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for num in nums:
            if len(heap) < k:
                heappush(heap, num)
            else:
                if heap[0] < num:
                    heapreplace(heap, num)
        return heap[0]


# k番目にでかい -> 上からk個 -> 長さkのmin-heapに詰めていって残ったやつの先頭