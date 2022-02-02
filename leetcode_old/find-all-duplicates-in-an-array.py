# Time O(n), Space: O(1)
# 「数字nums[i]が一つ存在する」を「nums[i]番目が負」で表現
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ret = []
        for num in nums:
            if nums[abs(num) - 1] < 0:
                ret.append(abs(num))
            else:
                nums[abs(num) - 1] = -nums[abs(num) - 1]
        return ret


# Time: O(n), Space: O(n)
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        seen = set()
        ret = list()
        for num in nums:
            if num in seen:
                ret.append(num)
            else:
                seen.add(num)
        return ret
