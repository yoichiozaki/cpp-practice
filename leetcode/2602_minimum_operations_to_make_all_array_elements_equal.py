class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        ans = []
        N = len(nums)
        prefix = [0] + list(accumulate(nums))
        for query in queries:
            idx = bisect_left(nums, query)
            ans.append((query * idx - prefix[idx]) + (prefix[N] - prefix[idx] - query * (N - idx)))
        return ans