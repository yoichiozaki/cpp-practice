# 3Sumは毎回targetの変わる2Sumとして解ける：https://zakimal.github.io/ja/post/n-sum-problems/
# targetとの差を記録しておいて小さければ更新していく
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        diff = float("inf")
        nums.sort()
        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                three_sum = nums[i] + nums[left] + nums[right]
                if abs(target - three_sum) < abs(diff):
                    diff = target - three_sum
                if three_sum < target:
                    left += 1
                else:
                    right -= 1
            if diff == 0:
                break
        return target - diff