# DFSで全探索
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)

        if s % k != 0:
            return False

        target = s // k
        partition_sums = [0 for _ in range(k)]
        nums.sort(reverse=True)

        def rec(curr):
            if curr == len(nums):
                for ps in partition_sums:
                    if ps != target:
                        return False
                return True

            for i in range(k):
                if partition_sums[i] + nums[curr] <= target:
                    partition_sums[i] += nums[curr]
                    if rec(curr + 1):
                        return True
                    partition_sums[i] -= nums[curr]
            return False

        return rec(0)
