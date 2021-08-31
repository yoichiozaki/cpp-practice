# brute-force
# 考えられる部分列を全部調べ上げ，各部分列に対してその和を一から求める
# Time: O(n^3)
# Space: O(1)
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = float("inf")
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                s = 0
                for num in nums[i:j+1]:
                    s += num
                if target <= s:
                    ans = min(ans, j - i + 1)
        return ans if ans != float("inf") else 0


# better brute-force
# 考えられる部分列を全部調べ上げる．ただし，各部分列の和を累積和を使って時間計算量O(1)で求める
# Time: O(n^2)
# Space: O(n)
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = float("inf")
        accum = [0 for _ in range(len(nums) + 1)]
        for i in range(1, len(nums) + 1):
            accum[i] = accum[i-1] + nums[i-1]

        for i in range(len(nums)):
            for j in range(i, len(nums)):
                s = accum[j+1] - accum[i]
                if target <= s:
                    ans = min(ans, j - i + 1)
        return ans if ans != float("inf") else 0


# binary search on accum
# 左端を固定したときに右端をどこにすべきか，は累積和を二分探索すれば求まる
# Time: O(n log n)
# Space: O(n)
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = float("inf")
        accum = [0 for _ in range(len(nums) + 1)]
        for i in range(1, len(nums) + 1):
            accum[i] = accum[i-1] + nums[i-1]

        for i in range(len(nums) + 1):
            j = bisect_left(accum, accum[i] + target)
            if j != len(accum):
                ans = min(ans, j - i)
        return ans if ans != float("inf") else 0


# 2 pointers，（尺取法）
# 一度左端を固定して右端を伸ばしていく．どこかのタイミングで和がtargetを超えるので，そのタイミングで左端を右に移動させていく．
# Time: O(n)
# Space: O(1)
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = float("inf")
        left = 0
        accum = 0
        for right in range(len(nums)):
            accum += nums[right]
            while target <= accum:
                ans = min(ans, right - left + 1)
                accum -= nums[left]
                left += 1
        return ans if ans != float("inf") else 0
