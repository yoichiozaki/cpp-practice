# 言われたとおりにソートする
# Time: O(n log n + k log k)
# Space: O(1)
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        arr = sorted(arr, key=lambda a: abs(a - x))
        arr = arr[:k]
        arr = sorted(arr)
        return arr


# 領域を広げていく
# Time: O(n - k)
# Space: O(1)
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        left = 0
        right = len(arr) - 1
        while k <= right - left:
            if x - arr[left] <= arr[right] - x:
                right -= 1  # rightのほうがxから遠い
            else:
                left += 1
        return arr[left:right+1]


# ソートされているので求めたい領域は連続する長さkの部分配列
# 最初に右端を二分探索で暫定で決めてそこから動かす
# Time: O(log n + k)
# Space: O(1)
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        right = bisect_left(arr, x)
        left = right - 1
        while 0 < k:
            if len(arr) <= right or (0 <= left and x - arr[left] <= arr[right] - x):
                left -= 1
            else:
                right += 1
            k -= 1
        return arr[left + 1:right]


# 最初の右端の位置はarr[0:n-k]内なのでそれを考慮
# Time: O(log (n - k) + k)
# Space: O(1)
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        right = bisect_left(arr[0:len(arr) - k], x)
        left = right - 1
        while 0 < k:
            if len(arr) <= right or (0 <= left and x - arr[left] <= arr[right] - x):
                left -= 1
            else:
                right += 1
            k -= 1
        return arr[left + 1:right]


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        left = 0
        right = len(arr) - k

        while left < right:
            mid = (left + right) // 2
            if x <= arr[mid]:
                right = mid
            elif arr[mid + k] <= x:
                left = mid + 1
            elif x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid

        return arr[left:left + k]
