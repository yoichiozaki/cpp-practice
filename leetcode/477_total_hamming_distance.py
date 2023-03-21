# TLE
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        def hamming_distance(x, y):
            return bin(x ^ y).count('1')
        ans = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                ans += hamming_distance(nums[i], nums[j])
        return ans


# 各桁ごとに立っている1の個数を数えれば、その桁で発生するハミング距離の合計が計算可能
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        total = 0
        for i in range(0, 32, 1):
            one = 0
            for num in nums:
                one += (num >> i) & 1
            total += one * (len(nums) - one)
        return total
