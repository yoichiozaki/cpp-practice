# 絶対値は外して場合分け -> 空にもなる連続する部分列の和の最大最小値はいくつか？という問題に言い換えられる -> Kadaneを2つやる
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        max_sofar = 0
        positive_ending_here = 0  # 空の部分列も許容される点に注意
        negative_ending_here = 0
        for num in nums:
            positive_ending_here = max(0, positive_ending_here + num)
            negative_ending_here = min(0, negative_ending_here + num)
            max_sofar = max(max_sofar, positive_ending_here, -
                            negative_ending_here)
        return max_sofar


# 求めるのが部分列の長さの最大値ではなくて部分列の和の最大値なので（？）累積和を取る過程で最大の変位を計算すればいい
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        top = 0
        bottom = 0
        s = 0
        for num in nums:
            s += num
            top = max(top, s)
            bottom = min(bottom, s)
        return top - bottom
