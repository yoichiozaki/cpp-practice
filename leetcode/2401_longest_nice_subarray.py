# 数列が与えられる。その数列の連続する部分列のうち、その部分列の要素を二進数表記した時にどの桁も1がダブらないような部分列の最大の長さを求めよ
# 連続する部分列 -> 尺取り法、累積和
# bitwise-orの逆演算はbitwise-xor
class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        ans = 0
        left = 0
        accum = 0
        for right in range(len(nums)):
            while accum & nums[right] != 0: # 尺取り法
                accum = accum ^ nums[left] # ここで累積or和からnums[left]を「減算」
                left += 1
            accum = accum | nums[right]
            ans = max(ans, right - left + 1)
        return ans