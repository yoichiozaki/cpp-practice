class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ret = []

        for i in range(len(nums) - 2):
            # 同じ数字をnums[i]として選ぶのを回避
            if 1 <= i and nums[i-1] == nums[i]:
                continue

            # two-sum
            left = i + 1
            right = len(nums) - 1
            while left < right:
                three_sum = nums[i] + nums[left] + nums[right]

                if three_sum == 0:
                    ret.append([nums[i], nums[left], nums[right]])

                    # 同じ数字をnums[left]として選ぶのを回避
                    while left < right and nums[left] == nums[left+1]:
                        left += 1

                    # 同じ数字をnums[right]として選ぶのを回避
                    while left < right and nums[right-1] == nums[right]:
                        right -= 1

                    # 次の数字を指すようにポインタをずらす
                    left += 1
                    right -= 1

                elif three_sum < 0:
                    left += 1

                else:
                    right -= 1

        return ret
