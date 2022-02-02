class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        # degreeを与える数字を全部含む部分列が求める部分列
        cnt = Counter(nums)
        degree = max(cnt.values())

        left, right = {}, {}
        for idx, num in enumerate(nums):
            if num not in left:
                left[num] = idx
            right[num] = idx

        ans = len(nums)
        for num in nums:
            if cnt[num] == degree:
                ans = min(ans, right[num] - left[num] + 1)
        return ans