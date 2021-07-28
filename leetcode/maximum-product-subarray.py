class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ret = nums[0]

        # _max, _min: 右端がnumsのi番目である部分列の積の最大値, 最小値
        _max = ret
        _min = ret

        for num in nums[1:]:
            if num < 0:
                _max, _min = _min, _max
            _max = max(num, _max * num)
            _min = min(num, _min * num)
            ret = max(_max, ret)
        return ret