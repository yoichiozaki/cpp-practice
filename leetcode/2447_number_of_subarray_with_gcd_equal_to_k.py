class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        ans = 0
        for i in range(len(nums)):
            j = i
            while j < len(nums) and nums[j] % k == 0:
                nums[i] = math.gcd(nums[i], nums[j])
                if nums[i] == k:
                    ans += 1
                j += 1
        return ans