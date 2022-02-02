# 全部ソートする
# Time: O(n log n)
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = sorted(list(set(nums)))
        if len(nums) < 3:
            return nums[-1]
        return nums[-3]


# 注目しておくべきは上位3位までだけ．それ以降の順位はいらないので，それだけ置い続ける
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        first = float("-inf")
        second = float("-inf")
        third = float("-inf")
        for num in nums:
            if num in (first, second, third):
                continue
            if first < num:
                first, num = num, first
            if second < num:
                second, num = num, second
            if third < num:
                third, num = num, third
        return first if third == float("-inf") else third
