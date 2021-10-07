# まず前提としてnumsに出てこない数字が最小の範囲の端点になることはない
# なぜなら，もしnumsに出てこない数字が答えの範囲に含まれるとすると，その範囲に含まれるnums内の数字を使ってその範囲を狭めることができるから．

# Blute-Force
# 範囲端点候補を全部調べる
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        range_min = float("-inf")
        range_max = float("inf")

        for i in range(len(nums)):
            for j in range(len(nums[i])):
                for k in range(i, len(nums)):
                    for l in range((j if k == i else 0), len(nums[k])):
                        current_min = min(nums[i][j], nums[k][l])
                        current_max = max(nums[i][j], nums[k][l])

                        # 各リストの数字を最低一つは含むかを確認
                        is_ok = True
                        for lst in nums:
                            is_ok = is_ok and any(
                                [current_min <= num <= current_max for num in lst])

                        # 全リストに対して[current_min, current_max]は条件を満たしている
                        if is_ok:
                            if current_max - current_min < range_max - range_min or (current_max - current_min == range_max - range_min and current_min < range_min):
                                range_min = current_min
                                range_max = current_max

        return [range_min, range_max]


# 賢いやり方
# まずnumsに含まれる各リストの先頭要素をすっぽり覆うような範囲は条件を満たす
# range = [min([lst[0] for lst in nums]), max([lst[0] for lst in nums])]
# ここからより「small」なものを探しに行く．range_minを上げる方向で範囲を検索していく
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        range_min = float("-inf")
        range_max = float("inf")

        next_index = [0 for _ in range(len(nums))]
        done_flag = False

        i = 0
        j = 0
        while i < len(nums) and not done_flag:
            while j < len(nums[i]) and not done_flag:

                min_idx = 0
                max_idx = 0
                for k in range(len(next_index)):
                    if nums[k][next_index[k]] < nums[min_idx][next_index[min_idx]]:
                        min_idx = k
                    if nums[max_idx][next_index[max_idx]] < nums[k][next_index[k]]:
                        max_idx = k

                current_min = nums[min_idx][next_index[min_idx]]
                current_max = nums[max_idx][next_index[max_idx]]

                if current_max - current_min < range_max - range_min or (current_max - current_min == range_max - range_min and current_min < range_min):
                    range_min = current_min
                    range_max = current_max

                next_index[min_idx] += 1
                if next_index[min_idx] == len(nums[min_idx]):
                    done_flag = True

                j += 1
            i += 1

        return [range_min, range_max]


# TODO: さらにheapqを使うともっと速い
