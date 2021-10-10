# nums[0]をflipするかどうかはすぐに決められるのでそこから貪欲に
class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        ans = 0
        flipped_at = [False for _ in range(len(nums))]  # i番目を左端としてk個flipしたか
        total_flip = 0
        for i in range(len(nums)):
            if k <= i:
                total_flip -= 1 if flipped_at[i - k] else 0

            # 初期状態で点灯かつこれまで偶数回flip
            # -> nums[i]を左端にflipしない
            if nums[i] == 1 and total_flip % 2 == 0:
                continue

            # 初期状態で消灯かつこれまで奇数回flip
            # -> nums[i]を左端にflipしない
            if nums[i] == 0 and total_flip % 2 == 1:
                continue

            # 初期状態で消灯かつこれまで偶数回flip
            # -> nums[i]を左端にflipする
            if nums[i] == 0 and total_flip % 2 == 0:
                # 連続するk個取れない
                if len(nums) < i + k:
                    return -1
                flipped_at[i] = True
                total_flip += 1
                ans += 1

            # 初期状態で点灯かつこれまで奇数回flip
            # -> nums[i]を左端にflipする
            if nums[i] == 1 and total_flip % 2 == 1:
                # 連続するk個取れない
                if len(nums) < i + k:
                    return -1
                flipped_at[i] = True
                total_flip += 1
                ans += 1

        return ans
