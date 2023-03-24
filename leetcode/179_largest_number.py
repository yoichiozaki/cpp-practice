from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def compare(a, b):
            return int(b + a) - int(a + b)
        nums = list(map(str, nums))
        nums.sort(key=cmp_to_key(compare))
        result = ''.join(nums)
        return result if result[0] != '0' else '0'