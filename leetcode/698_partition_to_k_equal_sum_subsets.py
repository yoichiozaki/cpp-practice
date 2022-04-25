class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        if s % k != 0:
            return False
        target = s // k
        partitions = [0 for _ in range(k)]
        nums.sort(reverse=True) # 大きい数字から使用することで枝刈り可能
        def dfs(pos):
            if pos == len(nums):
                for p in partitions:
                    if p != target:
                        return False
                return True
            for i in range(k):
                if partitions[i] + nums[pos] <= target:
                    partitions[i] += nums[pos]
                    if dfs(pos + 1):
                        return True
                    partitions[i] -= nums[pos]
            return False
        return dfs(0)