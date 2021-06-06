class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = dict()
        for idx, num in enumerate(nums):
            complement = target - num
            if complement in table.keys():
                return [idx, table[complement]]
            else:
                table[num] = idx
