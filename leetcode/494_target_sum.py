class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        memo = dict()
        # nums[:pos+1]まで使った加減算でtargetにする場合の数
        def rec(pos, sofar):
            if (pos, sofar) in memo:
                return memo[(pos, sofar)]
            if pos == -1:
                if sofar == target:
                    return 1
                else:
                    return 0
            else:
                positive = rec(pos - 1, sofar - nums[pos]) # nums[pos]を足すことでtargetになる場合
                negative = rec(pos - 1, sofar + nums[pos]) # nums[pos]を引くことでtargetになる場合
                memo[(pos, sofar)] = positive + negative
                return memo[(pos, sofar)]
        return rec(len(nums) - 1, 0)
    