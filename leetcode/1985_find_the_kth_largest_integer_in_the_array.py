class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        heap = []
        for num in nums:
            heappush(heap, int(num))
            if len(heap) > k:
                heappop(heap)
        return str(heap[0])