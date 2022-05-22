# 線形に調べる
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        N = len(nums)
        for i in range(N - 1):
            if nums[i] > nums[i + 1]:
                return i
        return N - 1


# 再帰的に二分探索
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        def binary_search(left, right):
            if left == right:
                return left
            mid = (left + right) // 2
            if nums[mid] > nums[mid + 1]:
                return binary_search(left, mid)
            else:
                return binary_search(mid + 1, right)
        return binary_search(0, len(nums) - 1)


# 反復的に二分探索
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        return left


# 添え字の考え方：mid = (left + right) // 2
# midは小さいほうに丸められる（left + 1 == rightの時を考える）ので終了条件を while left < right とするならループを抜ける状態の時がleft == rightのときで、leftが答え