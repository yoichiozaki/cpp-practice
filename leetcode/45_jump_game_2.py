class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0
        furthest = 0
        level = 0
        pos = 0 # 各階層末尾の位置を指し示す
        while pos <= furthest: # ここの一周で同じ階層の位置を全部訪れる
            _furthest = furthest
            while pos <= furthest:
                _furthest = max(_furthest, pos + nums[pos])
                if len(nums) - 1 <= _furthest: # 次の階層でnumsの右端を飛び越えるので終了
                    return level + 1
                pos += 1
            level += 1
            furthest = _furthest
        return -1


class Solution:
    def jump(self, nums: List[int]) -> int:
        # dp[i]: iに到達するのに必要な最小ジャンプ数
        dp = [float("inf") for _ in range(len(nums))]
        dp[0] = 0
        for pos, jump in enumerate(nums):
            for j in range(1, jump + 1):
                next_pos = min(pos + j, len(nums) - 1)
                dp[next_pos] = min(dp[next_pos], dp[pos] + 1)
        return dp[-1]


class Solution:
    def jump(self, nums: List[int]) -> int:
        # dp[i]: iに到達するのに必要な最小ジャンプ数
        dp = [float("inf") for _ in range(len(nums))]
        dp[0] = 0
        for pos, jump in enumerate(nums):
            j = 1
            while j <= jump and pos + j < len(nums):
                next_pos = pos + j
                dp[next_pos] = min(dp[next_pos], dp[pos] + 1)
                j += 1
        return dp[-1]