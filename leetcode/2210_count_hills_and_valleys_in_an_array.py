class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        shape = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] == shape[-1]:
                continue
            shape.append(nums[i])
        cnt = 0
        for i in range(1, len(shape) - 1):
            if (shape[i-1] < shape[i] and shape[i] > shape[i+1]) or (shape[i-1] > shape[i] and shape[i] < shape[i+1]):
                cnt += 1
        return cnt