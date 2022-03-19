class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = dict()  # {num: idx}
        for idx, num in enumerate(nums):
            complement = target - num
            if complement in table:
                return [idx, table[complement]]
            table[num] = idx


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        memo = dict()
        for idx, num in enumerate(nums):
            remain = target - num
            if remain in memo:
                return [idx, memo[remain]]
            memo[num] = idx
