class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        # 常に最小の要素を +1 するのが最適
        # 例えば x > y な [x, y] が与えられたとき、
        # (1) x += 1: x * y -> (x + 1) * y = x*y + y
        # (2) y += 1: x * y -> x * (y + 1) = x*y + x
        heapq.heapify(nums)
        for i in range(k):
            num = heapq.heappop(nums)
            num += 1
            heapq.heappush(nums, num)
        ans = 1
        while 0 < len(nums):
            num = heapq.heappop(nums)
            ans = (ans * num) % (10 ** 9 + 7)
        return ans