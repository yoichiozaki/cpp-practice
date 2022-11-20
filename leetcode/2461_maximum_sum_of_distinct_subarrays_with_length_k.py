# 今見てる数字を最後にいつ見かけたか、を記録しておいて（ということはそのために、今見た数字を見かけたタイミングも記録しながら）
# k個前までに見かけたか、で判断する。
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        current_sum = 0
        pos_of_dup = -1
        last_pos = [-1 for _ in range(100001)]
        for i in range(len(nums)):
            current_sum += nums[i]
            if k <= i:
                current_sum -= nums[i - k]
            pos_of_dup = max(pos_of_dup, last_pos[nums[i]])
            if k <= i - pos_of_dup:
                ans = max(ans, current_sum)
            last_pos[nums[i]] = i
        return ans