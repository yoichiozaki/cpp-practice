class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        N = len(nums)

        max_on_left = [None for _ in range(N)]
        x = float("-inf")
        for i in range(0, N, 1):
            max_on_left[i] = x
            x = max(x, nums[i])

        min_on_right = [None for _ in range(N)]
        x = float("+inf")
        for i in range(N-1, -1, -1):
            min_on_right[i] = x
            x = min(x, nums[i])

        score = 0
        for i in range(1, N-1, 1):
            if max_on_left[i] < nums[i] < min_on_right[i]:
                score += 2
            elif nums[i-1] < nums[i] < nums[i+1]:
                score += 1

        return score
