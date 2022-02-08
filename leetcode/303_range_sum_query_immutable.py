class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        accums = [0 for _ in range(len(nums) + 1)]  # accum[i] = sum(nums[0:i])
        for i in range(0, len(nums)):
            accums[i + 1] = accums[i] + nums[i]
        self.accums = accums

    def sumRange(self, left: int, right: int) -> int:
        return self.accums[right + 1] - self.accums[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)

class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.accum = [0]
        for num in nums:
            self.accum.append(self.accum[-1] + num)


    def sumRange(self, left: int, right: int) -> int:
        return self.accum[right+1] - self.accum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)