# Blute-force
# Time: O(n^2)
# Space: O(n)
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ret = [-1 for _ in range(len(nums))]
        doubled = nums + nums
        for i in range(len(nums)):
            for j in range(i + 1, i + len(nums)):
                if nums[i] < doubled[j]:
                    ret[i] = doubled[j]
                    break
        return ret


# Blute-force
# Time: O(n^2)
# Space: O(n)
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ret = [-1 for _ in range(len(nums))]
        for i in range(len(nums)):
            for j in range(1, len(nums)):
                if nums[i] < nums[(i + j) % len(nums)]:
                    ret[i] = nums[(i + j) % len(nums)]
                    break
        return ret


# 「nums[i]の次に大きい値」を見つけたいときに，
# - nums[i] <  nums[i+1] => nums[i+1]が「nums[i]の次に大きい値」
# - nums[i] >= nums[i+1] => 「nums[i+1]の次に大きい値，nums[i+2]の次に大きい値，...」が候補
# つまり，
# nums[i]の次に大きい値 = max(
#     nums[i+1]の次に大きい値,
#     nums[i+2]の次に大きい値,
#     ...
# )
# という部分問題に分けられる
# これをstackを用いて実装する
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ret = [-1 for _ in range(len(nums))]
        filled = [False for _ in range(len(nums))]
        stack = []  # nums[i]の次に大きい値の候補（nums[i+?]の次に大きい値）をメモ

        for i in range(len(nums) - 1, -1, -1):  # 後ろからループ
            while len(stack) != 0 and stack[-1] <= nums[i]:
                stack.pop()  # nums[i]以下なのでstack[-1]は答えにならない
            if len(stack) != 0:
                ret[i] = stack[-1]
                filled[i] = True
            stack.append(nums[i])  # nums[i]はnums[i-1]以降の「次に大きい値」の候補

        # サイクルになっているので2周しておけば十分
        for i in range(len(nums) - 1, -1, -1):
            if not filled[i]:
                while len(stack) != 0 and stack[-1] <= nums[i]:
                    stack.pop()
                if len(stack) != 0:
                    ret[i] = stack[-1]
                    filled[i] = True

        return ret
