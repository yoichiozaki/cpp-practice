# 真面目にソートする
# Time: O(n log n)
# Space: O(1)
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        return nums[-k]


# 長さkのheapを使う
# Time: O(n log k), O(n)回のheapへの追加O(log k)
# Space: O(k)
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for num in nums:
            if len(heap) < k:
                heapq.heappush(heap, num)
            else:
                if heap[0] < num:
                    heapq.heapreplace(heap, num)
        return heap[0]


# partitioningをクイックソート風に繰り返す
