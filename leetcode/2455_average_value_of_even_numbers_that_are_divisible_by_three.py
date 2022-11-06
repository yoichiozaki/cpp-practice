class Solution:
    def averageValue(self, nums: List[int]) -> int:
        lst = []
        for num in nums:
            if num % 2 == 0 and num % 3 == 0:
                lst.append(num)
        if len(lst) == 0:
            return 0
        return sum(lst) // len(lst)