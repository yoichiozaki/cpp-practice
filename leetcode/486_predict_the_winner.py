# 全通り調べ上げ。O(2^n)
# 「対player2で何点プラスか」を返す関数を考えて、部分問題から一つサイズの大きい問題の解を考える
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        memo = dict()
        def score_over_player2(nums, left, right, turn):
            if (left, right) in memo:
                return memo[(left, right)]
            if left == right:
                memo[(left, right)] = nums[left] * turn
                return memo[(left, right)]
            else:
                take_left = nums[left] * turn + score_over_player2(nums, left + 1, right, -turn)
                take_right = nums[right] * turn + score_over_player2(nums, left, right - 1, -turn)
                if turn == 1:
                    memo[(left, right)] = max(take_left, take_right)
                    return memo[(left, right)]
                else:
                    memo[(left, right)] = min(take_left, take_right)
                    return memo[(left, right)]
        if score_over_player2(nums, 0, len(nums) - 1, 1) >= 0:
            return True
        else:
            return False