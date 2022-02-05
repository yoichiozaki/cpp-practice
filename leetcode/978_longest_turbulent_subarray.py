# 連続した部分列に関する問題 -> しゃくとり法
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        N = len(arr)
        if N == 1:
            return 1

        def cmp(a, b):
            if a < b:
                return 1
            elif a == b:
                return 0
            else:  # a > b
                return -1

        ans = 1
        left = 0
        for right in range(1, N):
            c = cmp(arr[right-1], arr[right])
            if c == 0:
                left = right
            elif right == N-1 or c * cmp(arr[right], arr[right+1]) != -1:
                ans = max(ans, right - left + 1)
                left = right
        return ans
