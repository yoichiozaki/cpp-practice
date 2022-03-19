class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = dict()  # {num: idx}
        for idx, num in enumerate(nums):
            complement = target - num
            if complement in table:
                return [idx, table[complement]]
            table[num] = idx
