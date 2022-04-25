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
                return len(set(partitions)) == 1
                return True
            for i in range(k):
                if partitions[i] + nums[pos] <= target:
                    partitions[i] += nums[pos]
                    if dfs(pos + 1):
                        return True
                    partitions[i] -= nums[pos]
                    if partitions[i] == 0: # partitions[i]にnums[pos]を使えなかった結果partitions[i]に含まれる数字がないならそれ以降は調べるまでもない
                        break
            return False
        return dfs(0)